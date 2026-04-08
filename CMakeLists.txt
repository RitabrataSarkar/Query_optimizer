cmake_minimum_required(VERSION 3.14)
project(simple_query_optimizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(simple_query_optimizer
    src/main.cpp
    src/parser.cpp
    src/statistics.cpp
    src/cost_estimator.cpp
    src/enumerator.cpp
    src/plan_printer.cpp
    src/optimizer.cpp
)
