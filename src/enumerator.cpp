#include "enumerator.h"

#include <algorithm>
#include <sstream>
#include <unordered_set>

namespace {
std::string to_lower_copy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

std::string algo_to_string(JoinAlgorithm a) {
    switch (a) {
        case JoinAlgorithm::NestedLoop:
            return "NestedLoop";
        case JoinAlgorithm::Hash:
            return "Hash";
        case JoinAlgorithm::Merge:
            return "Merge";
    }
    return "Unknown";
}
}  // namespace

PlanEnumerator::PlanEnumerator(const CostEstimator& estimator) : estimator_(estimator) {}

std::vector<CandidatePlan> PlanEnumerator::enumerate(const Query& query, std::size_t max_candidates) const {
    std::vector<CandidatePlan> plans;

    if (query.tables.empty()) {
        return plans;
    }

    std::unordered_map<std::string, std::vector<FilterPredicate>> filter_map;
    for (const auto& filter : query.filters) {
        filter_map[to_lower_copy(filter.table)].push_back(filter);
    }

    std::unordered_map<std::string, std::shared_ptr<PlanNode>> base_plans;
    for (const auto& table : query.tables) {
        const auto key = to_lower_copy(table);
        if (base_plans.find(key) != base_plans.end()) {
            continue;
        }

        auto it = filter_map.find(key);
        const std::vector<FilterPredicate> filters = (it == filter_map.end()) ? std::vector<FilterPredicate>{} : it->second;
        auto base = estimator_.make_base_plan(key, filters);
        if (!base) {
            continue;
        }
        base_plans[key] = base;
    }

    for (const auto& table : query.tables) {
        const auto key = to_lower_copy(table);
        auto found = base_plans.find(key);
        if (found == base_plans.end()) {
            continue;
        }

        State start;
        start.plan = found->second;
        start.order.push_back(key);

        dfs_enumerate(query, filter_map, base_plans, start, plans, max_candidates);
        if (plans.size() >= max_candidates) {
            break;
        }
    }

    std::sort(plans.begin(), plans.end(), [](const CandidatePlan& a, const CandidatePlan& b) {
        return a.estimated_cost < b.estimated_cost;
    });

    return plans;
}

void PlanEnumerator::dfs_enumerate(const Query& query,
                                   const std::unordered_map<std::string, std::vector<FilterPredicate>>& filter_map,
                                   const std::unordered_map<std::string, std::shared_ptr<PlanNode>>& base_plans,
                                   State current,
                                   std::vector<CandidatePlan>& out,
                                   std::size_t max_candidates) const {
    (void)filter_map;
    if (out.size() >= max_candidates) {
        return;
    }

    if (current.order.size() == query.tables.size()) {
        CandidatePlan cp;
        cp.root = current.plan;
        cp.estimated_cost = current.plan->estimated_cost;
        cp.estimated_rows = current.plan->estimated_rows;
        cp.summary = build_summary(current.order, current.algorithms);
        out.push_back(cp);
        return;
    }

    std::unordered_set<std::string> used(current.order.begin(), current.order.end());
    std::vector<std::string> remaining;
    for (const auto& table : query.tables) {
        const auto key = to_lower_copy(table);
        if (used.find(key) == used.end()) {
            remaining.push_back(key);
        }
    }

    // Heuristic: Sort remaining candidate tables by their base plan estimated rows
    // This pushes the optimizer to evaluate smaller joins first, significantly improving the early candidate plans.
    std::sort(remaining.begin(), remaining.end(), [&base_plans](const std::string& a, const std::string& b) {
        auto it_a = base_plans.find(a);
        auto it_b = base_plans.find(b);
        double rows_a = (it_a != base_plans.end() && it_a->second) ? it_a->second->estimated_rows : 1e9;
        double rows_b = (it_b != base_plans.end() && it_b->second) ? it_b->second->estimated_rows : 1e9;
        return rows_a < rows_b;
    });

    for (const auto& candidate : remaining) {
        if (out.size() >= max_candidates) {
            return;
        }

        if (!has_join_edge(current.order, candidate, query)) {
            continue;
        }

        const JoinPredicate join_pred = select_join_predicate(current.order, candidate, query);
        const auto right_it = base_plans.find(candidate);
        if (right_it == base_plans.end()) {
            continue;
        }

        for (const auto algo : {JoinAlgorithm::NestedLoop, JoinAlgorithm::Hash, JoinAlgorithm::Merge}) {
            if (out.size() >= max_candidates) {
                return;
            }

            auto joined = estimator_.make_join_plan(current.plan, right_it->second, join_pred, algo);
            if (!joined) {
                continue;
            }

            State next = current;
            next.plan = joined;
            next.order.push_back(candidate);
            next.algorithms.push_back(algo);
            dfs_enumerate(query, filter_map, base_plans, next, out, max_candidates);
        }
    }
}

bool PlanEnumerator::has_join_edge(const std::vector<std::string>& included,
                                   const std::string& candidate,
                                   const Query& query) const {
    std::unordered_set<std::string> inc(included.begin(), included.end());
    const auto cand = to_lower_copy(candidate);

    for (const auto& join : query.joins) {
        const auto l = to_lower_copy(join.left_table);
        const auto r = to_lower_copy(join.right_table);
        if ((inc.find(l) != inc.end() && r == cand) || (inc.find(r) != inc.end() && l == cand)) {
            return true;
        }
    }
    return false;
}

JoinPredicate PlanEnumerator::select_join_predicate(const std::vector<std::string>& included,
                                                    const std::string& candidate,
                                                    const Query& query) const {
    std::unordered_set<std::string> inc(included.begin(), included.end());
    const auto cand = to_lower_copy(candidate);

    for (const auto& join : query.joins) {
        const auto l = to_lower_copy(join.left_table);
        const auto r = to_lower_copy(join.right_table);
        if ((inc.find(l) != inc.end() && r == cand) || (inc.find(r) != inc.end() && l == cand)) {
            return join;
        }
    }

    JoinPredicate fallback;
    fallback.left_table = included.front();
    fallback.left_column = "id";
    fallback.right_table = cand;
    fallback.right_column = "id";
    return fallback;
}

std::string PlanEnumerator::build_summary(const std::vector<std::string>& order,
                                          const std::vector<JoinAlgorithm>& algos) const {
    std::ostringstream oss;
    oss << "Order: ";
    for (std::size_t i = 0; i < order.size(); ++i) {
        if (i > 0) {
            oss << " -> ";
        }
        oss << order[i];
    }

    if (!algos.empty()) {
        oss << " | Joins: ";
        for (std::size_t i = 0; i < algos.size(); ++i) {
            if (i > 0) {
                oss << ", ";
            }
            oss << algo_to_string(algos[i]);
        }
    }

    return oss.str();
}
