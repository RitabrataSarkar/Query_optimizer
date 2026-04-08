# Simple Query Optimizer (DBMS Lab)

A robust **cost-based query optimizer** in C++ for DBMS lab demonstration. The optimizer parses SQL queries, models query costs, and generates execution strategies, applying heuristics and memory estimation strategies.

## Implemented Pipeline

1. **Query Input (CLI)**: Accepts SQL commands.
2. **Logical Query Plan Generation**: Translates into an internal Node Tree.
3. **Candidate Plan Enumeration**: Exhaustively generates candidate trees using a Left-Deep DFS search.
4. **Pruning & Heuristics**: Applies pre-sort heuristics to base-plans to heavily speed up the optimizer's pathfinding execution.
5. **Multi-Dimensional Cost Estimation**: Computes explicit IO, CPU, and Memory usage costs during optimization.
6. **Optimal Plan Selection & Output**: Top candidate rendering.

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

## Cost Model 

The optimizer breaks down costs into distinct evaluation parameters:
- **CPU Cost**: Estimated compute for scan iterations and join conditions based on algorithm overhead.
- **IO Cost**: Disk page access approximations.
- **Memory Cost**: Memory buffers consumed by tracking variables. 

## Project Structure

- `include/`: robust headers containing modern `[[nodiscard]]` and secure memory paradigms.
- `src/`: C++ implementations, cost calculation logic, and CLI entry point.
- `examples/`: sample SQL queries
- `test_suite.py`: Automated testing framework

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Run

```bash
# Executable
./build/simple_query_optimizer

# Integration Test Suite
python test_suite.py
```

On Windows with MSVC generator, the built executable might be located at `build/Debug/simple_query_optimizer.exe`.

## CLI Commands

- `help` : show SQL syntax
- `stats` : show tables in statistics catalog
- `exit` : quit

## Project Features and Scope

- Represents fundamental cost-based parsing techniques inside relational paradigms.
- Plan enumeration is heavily pruned by pre-sorting cardinality calculations prior to execution.
- Includes thorough error handling through localized `OptimizerException` derivations.
