#pragma once

#include <vector>

#include "models.h"
#include "statistics.h"

class CostEstimator {
public:
    explicit CostEstimator(const StatisticsCatalog& catalog);

    [[nodiscard]] std::shared_ptr<PlanNode> make_base_plan(const std::string& table, const std::vector<FilterPredicate>& filters) const;
    [[nodiscard]] std::shared_ptr<PlanNode> make_join_plan(const std::shared_ptr<PlanNode>& left,
                                             const std::shared_ptr<PlanNode>& right,
                                             const JoinPredicate& predicate,
                                             JoinAlgorithm algorithm) const;

private:
    [[nodiscard]] double estimate_filter_selectivity(const std::string& table, const FilterPredicate& filter) const;
    [[nodiscard]] double estimate_join_selectivity(const JoinPredicate& predicate) const;

    const StatisticsCatalog& catalog_;
};
