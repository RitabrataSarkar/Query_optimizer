#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class OptimizerException : public std::runtime_error {
public:
    explicit OptimizerException(const std::string& msg) : std::runtime_error(msg) {}
};

enum class OperatorType {
    TableScan,
    Selection,
    Join
};

enum class JoinAlgorithm {
    NestedLoop,
    Hash,
    Merge
};

struct FilterPredicate {
    std::string table;
    std::string column;
    std::string op;
    std::string value;
};

struct JoinPredicate {
    std::string left_table;
    std::string left_column;
    std::string right_table;
    std::string right_column;
};

struct Query {
    std::vector<std::string> select_columns;
    std::vector<std::string> tables;
    std::vector<FilterPredicate> filters;
    std::vector<JoinPredicate> joins;
};

struct TableStats {
    std::string name;
    double row_count = 0.0;
    double row_size_bytes = 0.0;
    std::unordered_map<std::string, double> selectivity_by_column;
};

struct PlanNode {
    OperatorType type = OperatorType::TableScan;
    JoinAlgorithm join_algo = JoinAlgorithm::NestedLoop;

    std::string table;
    std::vector<FilterPredicate> filters;
    JoinPredicate join_predicate;

    double estimated_rows = 0.0;
    double estimated_cost = 0.0;
    double estimated_cpu_cost = 0.0;
    double estimated_memory_cost = 0.0;
    double estimated_io_cost = 0.0;

    std::shared_ptr<PlanNode> left;
    std::shared_ptr<PlanNode> right;
};

struct CandidatePlan {
    std::shared_ptr<PlanNode> root;
    double estimated_cost = 0.0;
    double estimated_rows = 0.0;
    std::string summary;
};
