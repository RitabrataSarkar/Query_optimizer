#pragma once

#include <string>

#include "models.h"

class QueryParser {
public:
    [[nodiscard]] Query parse(const std::string& sql) const;
};
