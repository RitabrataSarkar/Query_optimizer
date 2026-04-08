#pragma once

#include <unordered_map>
#include <vector>

#include "cost_estimator.h"
#include "models.h"

class PlanEnumerator {
public:
    explicit PlanEnumerator(const CostEstimator& estimator);

    [[nodiscard]] std::vector<CandidatePlan> enumerate(const Query& query, std::size_t max_candidates = 200) const;

private:
    struct State {
        std::shared_ptr<PlanNode> plan;
        std::vector<std::string> order;
        std::vector<JoinAlgorithm> algorithms;
    };

    void dfs_enumerate(const Query& query,
                       const std::unordered_map<std::string, std::vector<FilterPredicate>>& filter_map,
                       const std::unordered_map<std::string, std::shared_ptr<PlanNode>>& base_plans,
                       State current,
                       std::vector<CandidatePlan>& out,
                       std::size_t max_candidates) const;

    [[nodiscard]] bool has_join_edge(const std::vector<std::string>& included, const std::string& candidate, const Query& query) const;
    [[nodiscard]] JoinPredicate select_join_predicate(const std::vector<std::string>& included, const std::string& candidate, const Query& query) const;
    [[nodiscard]] std::string build_summary(const std::vector<std::string>& order, const std::vector<JoinAlgorithm>& algos) const;

    const CostEstimator& estimator_;
};
