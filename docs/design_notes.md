# Design Notes

## Modules

- Query Interface: `src/main.cpp`
- Logical Plan Generator: parser + base plan builder in `main.cpp`
- Plan Enumerator: `src/enumerator.cpp`
- Cost Estimator: `src/cost_estimator.cpp`
- Query Optimizer: `src/optimizer.cpp`
- Plan Display Module: `src/plan_printer.cpp`

## Core Data Structures

- Query representation (`Query`)
- Predicates (`FilterPredicate`, `JoinPredicate`)
- Statistics catalog (`TableStats`, `StatisticsCatalog`)
- Plan tree (`PlanNode`)
- Candidate container (`CandidatePlan`)

## Enumeration Strategy

- Left-deep tree enumeration
- Different join order exploration
- Different join algorithm choices at each step
- Candidate cap to bound complexity

## Future Extensions

- Predicate pushdown as separate operator node
- Bushy tree enumeration with DP
- Histogram-based selectivity
- Better SQL parser and alias handling
