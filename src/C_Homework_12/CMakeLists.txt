cmake_minimum_required(VERSION 3.10)
project(StackProjects)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(binary_representation
    binary_representation.c
)

target_include_directories(SortedList PRIVATE .)

enable_testing()
add_test(NAME binary_representation COMMAND tests_to_binary_representation --test)