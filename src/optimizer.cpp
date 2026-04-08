#include "optimizer.h"

QueryOptimizer::QueryOptimizer(const PlanEnumerator& enumerator) : enumerator_(enumerator) {}

std::vector<CandidatePlan> QueryOptimizer::optimize(const Query& query, std::size_t max_candidates) const {
    return enumerator_.enumerate(query, max_candidates);
}
