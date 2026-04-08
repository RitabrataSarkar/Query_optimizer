#pragma once

#include <string>

#include "models.h"

class PlanPrinter {
public:
    [[nodiscard]] std::string render_tree(const std::shared_ptr<PlanNode>& root) const;

private:
    [[nodiscard]] std::string render_node(const std::shared_ptr<PlanNode>& node, int depth) const;
    [[nodiscard]] std::string op_to_string(OperatorType op) const;
    [[nodiscard]] std::string join_algo_to_string(JoinAlgorithm algo) const;
};
