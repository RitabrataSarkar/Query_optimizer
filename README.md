# Simple SQL Query Optimizer ⚙️

**Developed collaboratively by team FIERY-FIVE under DBMS LAB Coursework.**

This repository houses a custom-built, cost-based SQL Query Optimizer developed in C++. The system is designed to demonstrate how modern relational database systems internally estimate the cost of query execution and select optimized execution strategies. 

By taking raw SQL queries as input, the system utilizes a C-based Lex/Yacc parser to generate an initial logical execution plan (Abstract Syntax Tree). Our C++ optimization engine then generates candidate plans, explores different join orders (such as Nested Loop and Hash Joins), calculates computational costs based on simulated database statistics, and outputs the most efficient query execution plan.

### Core Features
* **SQL Parsing:** Converts simplified SQL queries into relational algebra trees.
* **Plan Enumeration:** Explores alternative execution plans and different join strategies.
* **Cost Estimation:** Calculates CPU, memory, and I/O costs using database statistics.
* **Optimal Selection:** Outputs the lowest-cost execution plan alongside candidate comparisons.

### Tech Stack
* **Language:** C++ (Optimization Engine) / C (Lex/Yacc Parser)
* **Environment:** Linux-based command-line interface
