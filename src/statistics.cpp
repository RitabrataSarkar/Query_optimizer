#include "statistics.h"

#include <algorithm>

namespace {
std::string to_lower_copy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}
}  // namespace

StatisticsCatalog::StatisticsCatalog() {
    TableStats employees;
    employees.name = "employees";
    employees.row_count = 100000;
    employees.row_size_bytes = 128;
    employees.selectivity_by_column = {
        {"id", 0.00001},
        {"dept_id", 0.05},
        {"salary", 0.2},
        {"age", 0.4}
    };

    TableStats departments;
    departments.name = "departments";
    departments.row_count = 1000;
    departments.row_size_bytes = 64;
    departments.selectivity_by_column = {
        {"id", 0.001},
        {"location", 0.2}
    };

    TableStats projects;
    projects.name = "projects";
    projects.row_count = 50000;
    projects.row_size_bytes = 96;
    projects.selectivity_by_column = {
        {"id", 0.00002},
        {"dept_id", 0.05},
        {"status", 0.3}
    };

    TableStats assignments;
    assignments.name = "assignments";
    assignments.row_count = 300000;
    assignments.row_size_bytes = 48;
    assignments.selectivity_by_column = {
        {"emp_id", 0.03},
        {"project_id", 0.02}
    };

    tables_.emplace(employees.name, employees);
    tables_.emplace(departments.name, departments);
    tables_.emplace(projects.name, projects);
    tables_.emplace(assignments.name, assignments);
}

const TableStats* StatisticsCatalog::get_table(const std::string& table_name) const {
    const auto key = to_lower_copy(table_name);
    const auto it = tables_.find(key);
    if (it == tables_.end()) {
        return nullptr;
    }
    return &it->second;
}

std::vector<std::string> StatisticsCatalog::list_tables() const {
    std::vector<std::string> names;
    names.reserve(tables_.size());
    for (const auto& pair : tables_) {
        names.push_back(pair.first);
    }
    std::sort(names.begin(), names.end());
    return names;
}
