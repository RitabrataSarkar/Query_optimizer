#include "plan_printer.h"

#include <iomanip>
#include <sstream>

std::string PlanPrinter::render_tree(const std::shared_ptr<PlanNode>& root) const {
    if (!root) {
        return "<empty plan>\n";
    }
    return render_node(root, 0);
}

std::string PlanPrinter::render_node(const std::shared_ptr<PlanNode>& node, int depth) const {
    if (!node) {
        return "";
    }

    std::ostringstream oss;
    const std::string indent(static_cast<std::size_t>(depth) * 2, ' ');

    oss << indent << "- " << op_to_string(node->type);
    if (node->type == OperatorType::TableScan || node->type == OperatorType::Selection) {
        oss << " [table=" << node->table << "]";
        if (!node->filters.empty()) {
            oss << " [filters=" << node->filters.size() << "]";
        }
    }
    if (node->type == OperatorType::Join) {
        oss << " [algo=" << join_algo_to_string(node->join_algo) << "]"
            << " [on=" << node->join_predicate.left_table << "." << node->join_predicate.left_column
            << " = " << node->join_predicate.right_table << "." << node->join_predicate.right_column << "]";
    }

    oss << " [rows=" << std::fixed << std::setprecision(2) << node->estimated_rows << "]"
        << " [cost=" << std::fixed << std::setprecision(2) << node->estimated_cost << "]"
        << " (cpu=" << node->estimated_cpu_cost << ", io=" << node->estimated_io_cost << ", mem=" << node->estimated_memory_cost << ")\n";

    oss << render_node(node->left, depth + 1);
    oss << render_node(node->right, depth + 1);
    return oss.str();
}

std::string PlanPrinter::op_to_string(OperatorType op) const {
    switch (op) {
        case OperatorType::TableScan:
            return "TableScan";
        case OperatorType::Selection:
            return "Selection";
        case OperatorType::Join:
            return "Join";
    }
    return "Unknown";
}

std::string PlanPrinter::join_algo_to_string(JoinAlgorithm algo) const {
    switch (algo) {
        case JoinAlgorithm::NestedLoop:
            return "NestedLoop";
        case JoinAlgorithm::Hash:
            return "Hash";
        case JoinAlgorithm::Merge:
            return "Merge";
    }
    return "Unknown";
}
