#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "cost_estimator.h"
#include "enumerator.h"
#include "optimizer.h"
#include "parser.h"
#include "plan_printer.h"
#include "statistics.h"

namespace {
std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        --end;
    }
    return s.substr(start, end - start);
}

void print_intro() {
    std::cout << "Simple Query Optimizer (DBMS Lab)\n";
    std::cout << "Type SQL query or command: stats, help, exit\n\n";
}

void print_help() {
    std::cout << "Supported query pattern:\n";
    std::cout << "SELECT col1, col2 FROM t1 JOIN t2 ON t1.a = t2.b [JOIN ...] [WHERE t1.x > 10 AND t2.y = 5];\n";
    std::cout << "\nCommands:\n";
    std::cout << "  stats : show available table statistics\n";
    std::cout << "  help  : show syntax help\n";
    std::cout << "  exit  : quit program\n\n";
}

void print_stats(const StatisticsCatalog& catalog) {
    std::cout << "Available tables in statistics catalog:\n";
    for (const auto& table : catalog.list_tables()) {
        const TableStats* t = catalog.get_table(table);
        if (!t) {
            continue;
        }
        std::cout << "  - " << t->name
                  << " | rows=" << static_cast<long long>(t->row_count)
                  << " | row_size=" << static_cast<long long>(t->row_size_bytes) << " bytes\n";
    }
    std::cout << '\n';
}

CandidatePlan build_initial_plan(const Query& query, const CostEstimator& estimator) {
    CandidatePlan result;
    if (query.tables.empty()) {
        return result;
    }

    std::unordered_map<std::string, std::vector<FilterPredicate>> filter_map;
    for (const auto& filter : query.filters) {
        filter_map[filter.table].push_back(filter);
    }

    auto it = filter_map.find(query.tables[0]);
    std::vector<FilterPredicate> first_filters = (it == filter_map.end()) ? std::vector<FilterPredicate>{} : it->second;
    auto plan = estimator.make_base_plan(query.tables[0], first_filters);

    for (std::size_t i = 1; i < query.tables.size() && plan; ++i) {
        const auto& table = query.tables[i];
        auto f_it = filter_map.find(table);
        std::vector<FilterPredicate> filters = (f_it == filter_map.end()) ? std::vector<FilterPredicate>{} : f_it->second;
        auto right = estimator.make_base_plan(table, filters);
        if (!right) {
            continue;
        }

        JoinPredicate pred;
        bool found = false;
        for (const auto& join : query.joins) {
            if ((join.left_table == query.tables[i - 1] && join.right_table == table) ||
                (join.right_table == query.tables[i - 1] && join.left_table == table)) {
                pred = join;
                found = true;
                break;
            }
        }

        if (!found) {
            pred.left_table = query.tables[i - 1];
            pred.left_column = "id";
            pred.right_table = table;
            pred.right_column = "id";
        }

        plan = estimator.make_join_plan(plan, right, pred, JoinAlgorithm::NestedLoop);
    }

    result.root = plan;
    if (plan) {
        result.estimated_cost = plan->estimated_cost;
        result.estimated_rows = plan->estimated_rows;
        result.summary = "Initial logical plan (query order, nested-loop joins)";
    }
    return result;
}
}  // namespace

int main() {
    StatisticsCatalog catalog;
    QueryParser parser;
    CostEstimator estimator(catalog);
    PlanEnumerator enumerator(estimator);
    QueryOptimizer optimizer(enumerator);
    PlanPrinter printer;

    print_intro();
    print_help();

    std::string input;
    while (true) {
        std::cout << "SQL> ";
        if (!std::getline(std::cin, input)) {
            break;
        }

        const auto cmd = trim(input);
        if (cmd.empty()) {
            continue;
        }
        if (cmd == "exit" || cmd == "quit") {
            break;
        }
        if (cmd == "help") {
            print_help();
            continue;
        }
        if (cmd == "stats") {
            print_stats(catalog);
            continue;
        }

        try {
            Query query = parser.parse(cmd);
            CandidatePlan initial = build_initial_plan(query, estimator);
            auto candidates = optimizer.optimize(query, 200);

            if (!initial.root) {
                std::cout << "Could not build initial plan.\n\n";
                continue;
            }

            std::cout << "\n== Initial Logical Plan ==\n";
            std::cout << initial.summary << "\n";
            std::cout << "Estimated cost: " << std::fixed << std::setprecision(2) << initial.estimated_cost << "\n";
            std::cout << printer.render_tree(initial.root) << "\n";

            if (candidates.empty()) {
                std::cout << "No candidate plans generated. Check join predicates and tables.\n\n";
                continue;
            }

            std::cout << "== Candidate Plans (Top 10 by cost) ==\n";
            const std::size_t limit = std::min<std::size_t>(10, candidates.size());
            for (std::size_t i = 0; i < limit; ++i) {
                const auto& c = candidates[i];
                std::cout << (i + 1) << ". " << c.summary
                          << " | cost=" << std::fixed << std::setprecision(2) << c.estimated_cost
                          << " | rows=" << std::fixed << std::setprecision(2) << c.estimated_rows << "\n";
            }

            const auto& best = candidates.front();
            std::cout << "\n== Selected Optimized Plan ==\n";
            std::cout << best.summary << "\n";
            std::cout << "Estimated cost: " << std::fixed << std::setprecision(2) << best.estimated_cost << "\n";
            std::cout << printer.render_tree(best.root) << "\n";
        } catch (const std::exception& ex) {
            std::cout << "Error: " << ex.what() << "\n\n";
        }
    }

    std::cout << "Exiting optimizer.\n";
    return 0;
}
