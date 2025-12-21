cmake_minimum_required(VERSION 3.10)
project(Homework4)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(OptimalSorting
        OptimalSorting.c
)

target_include_directories(OptimalSorting PRIVATE .)