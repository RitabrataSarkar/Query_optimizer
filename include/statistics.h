#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "models.h"

class StatisticsCatalog {
public:
    StatisticsCatalog();

    [[nodiscard]] const TableStats* get_table(const std::string& table_name) const;
    [[nodiscard]] std::vector<std::string> list_tables() const;

private:
    std::unordered_map<std::string, TableStats> tables_;
};
