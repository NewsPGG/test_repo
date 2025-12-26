cmake_minimum_required(VERSION 3.10)
project(StackProjects)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(extended_bracket_balance
    extended_bracket_balance.c
    Stack.c
)

add_executable(sorting_station
    Sorting_station.c
    Stack.c
)

target_include_directories(extended_bracket_balance PRIVATE .)
target_include_directories(sorting_station PRIVATE .)