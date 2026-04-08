#pragma once

#include <vector>

#include "enumerator.h"
#include "models.h"

class QueryOptimizer {
public:
    explicit QueryOptimizer(const PlanEnumerator& enumerator);

    [[nodiscard]] std::vector<CandidatePlan> optimize(const Query& query, std::size_t max_candidates = 200) const;

private:
    const PlanEnumerator& enumerator_;
};
