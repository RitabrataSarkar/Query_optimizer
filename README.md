# Simple Query Optimizer (DBMS Lab)

A simplified **cost-based query optimizer** in C++ for DBMS lab demonstration.

## Implemented Pipeline

1. Query Input (CLI)
2. Logical Query Plan Generation
3. Candidate Plan Enumeration
4. Cost Estimation
5. Optimal Plan Selection
6. Optimized Plan Output

## Supported SQL Subset

- `SELECT ... FROM ...`
- `JOIN ... ON table1.col = table2.col`
- `WHERE` with `AND`
- Filters in the form `table.col op value`

Example:

```sql
SELECT e.id, d.id
FROM employees JOIN departments ON employees.dept_id = departments.id
WHERE employees.salary > 50000;
```

## Supported Operators

- Table Scan / Selection
- Join algorithms:
  - Nested Loop Join
  - Hash Join
  - Merge Join

## Cost Model (Simplified)

- Base scan cost + filter CPU cost
- Join output rows estimated using selectivity
- Join cost formulas differ by join algorithm
- Lowest estimated cost plan is selected

## Project Structure

- `include/`: headers for parser, model, statistics, cost estimator, enumerator, optimizer, printer
- `src/`: C++ implementations and CLI entry point
- `examples/`: sample SQL queries

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/simple_query_optimizer
```

On Windows with MSVC generator, executable may be under `build/Debug/`.

## CLI Commands

- `help` : show SQL syntax
- `stats` : show tables in statistics catalog
- `exit` : quit

## Notes and Scope

- This is a teaching project, not a production SQL optimizer.
- Parsing is intentionally strict and supports a limited SQL grammar.
- Plan enumeration is left-deep and capped by max candidate count for tractability.
