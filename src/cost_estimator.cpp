#include "cost_estimator.h"

#include <algorithm>
#include <cmath>

namespace {
constexpr double kSeqScanWeight = 1.0;
constexpr double kFilterCpuWeight = 0.2;
constexpr double kNestedLoopWeight = 1.0;
constexpr double kHashJoinWeight = 3.0;
constexpr double kMergeJoinWeight = 2.0;

std::string to_lower_copy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}
}  // namespace

CostEstimator::CostEstimator(const StatisticsCatalog& catalog) : catalog_(catalog) {}

std::shared_ptr<PlanNode> CostEstimator::make_base_plan(const std::string& table,
                                                        const std::vector<FilterPredicate>& filters) const {
    const TableStats* stats = catalog_.get_table(table);
    if (!stats) {
        return nullptr;
    }

    double combined_selectivity = 1.0;
    for (const auto& filter : filters) {
        combined_selectivity *= estimate_filter_selectivity(table, filter);
    }

    const double output_rows = std::max(1.0, stats->row_count * combined_selectivity);
    const double scan_cpu_cost = stats->row_count * kSeqScanWeight;
    const double filter_cpu_cost = stats->row_count * kFilterCpuWeight * static_cast<double>(filters.size());
    const double io_cost = (stats->row_count * stats->row_size_bytes) / 4096.0;

    auto node = std::make_shared<PlanNode>();
    node->type = filters.empty() ? OperatorType::TableScan : OperatorType::Selection;
    node->table = to_lower_copy(table);
    node->filters = filters;
    node->estimated_rows = output_rows;
    node->estimated_cpu_cost = scan_cpu_cost + filter_cpu_cost;
    node->estimated_io_cost = std::max(1.0, io_cost);
    // Early Filtering pushdown means we buffer fewer output rows to memory
    node->estimated_memory_cost = std::max(1.0, (output_rows * stats->row_size_bytes) / 4096.0);
    node->estimated_cost = node->estimated_cpu_cost + node->estimated_io_cost;
    return node;
}

std::shared_ptr<PlanNode> CostEstimator::make_join_plan(const std::shared_ptr<PlanNode>& left,
                                                        const std::shared_ptr<PlanNode>& right,
                                                        const JoinPredicate& predicate,
                                                        JoinAlgorithm algorithm) const {
    if (!left || !right) {
        return nullptr;
    }

    const double join_sel = estimate_join_selectivity(predicate);
    const double out_rows = std::max(1.0, left->estimated_rows * right->estimated_rows * join_sel);

    double cpu_cost = 0.0;
    double mem_cost = 0.0;
    double io_cost = 0.0;
    
    switch (algorithm) {
        case JoinAlgorithm::NestedLoop:
            cpu_cost = kNestedLoopWeight * (left->estimated_rows * right->estimated_rows);
            mem_cost = 2.0; // Page sizes
            break;
        case JoinAlgorithm::Hash:
            cpu_cost = kHashJoinWeight * (left->estimated_rows + right->estimated_rows);
            mem_cost = left->estimated_rows; // Build table memory footprint
            break;
        case JoinAlgorithm::Merge:
            cpu_cost = kMergeJoinWeight * (
                (left->estimated_rows * std::log2(left->estimated_rows + 1.0)) +
                (right->estimated_rows * std::log2(right->estimated_rows + 1.0))
            );
            mem_cost = 10.0; // Sort buffers
            io_cost = left->estimated_rows + right->estimated_rows; // Sort passes IO overhead
            break;
    }

    auto node = std::make_shared<PlanNode>();
    node->type = OperatorType::Join;
    node->join_algo = algorithm;
    node->join_predicate = predicate;
    node->left = left;
    node->right = right;
    node->estimated_rows = out_rows;
    node->estimated_cpu_cost = left->estimated_cpu_cost + right->estimated_cpu_cost + cpu_cost;
    node->estimated_io_cost = left->estimated_io_cost + right->estimated_io_cost + io_cost;
    node->estimated_memory_cost = std::max({left->estimated_memory_cost, right->estimated_memory_cost, mem_cost});
    node->estimated_cost = node->estimated_cpu_cost + node->estimated_io_cost;
    return node;
}

double CostEstimator::estimate_filter_selectivity(const std::string& table, const FilterPredicate& filter) const {
    const TableStats* stats = catalog_.get_table(table);
    if (!stats) {
        return 0.5;
    }

    const auto col = to_lower_copy(filter.column);
    const auto it = stats->selectivity_by_column.find(col);
    if (it != stats->selectivity_by_column.end()) {
        return it->second;
    }

    const std::string op = filter.op;
    if (op == "=") {
        return 0.1;
    }
    return 0.3;
}

double CostEstimator::estimate_join_selectivity(const JoinPredicate& predicate) const {
    const TableStats* left = catalog_.get_table(predicate.left_table);
    const TableStats* right = catalog_.get_table(predicate.right_table);
    if (!left || !right) {
        return 0.1;
    }

    const double max_rows = std::max(left->row_count, right->row_count);
    if (max_rows <= 0) {
        return 0.1;
    }

    return std::max(0.000001, 1.0 / max_rows);
}
