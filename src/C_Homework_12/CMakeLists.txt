cmake_minimum_required(VERSION 3.10)
project(Homework12)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(binary_representation
    binary_representation.c
)

add_executable(double_parser
        double_parser.c
)

target_include_directories(binary_representation PRIVATE .)
target_include_directories(double_parser PRIVATE .)

enable_testing()
add_test(NAME binary_representation COMMAND tests_to_binary_representation --test)
add_test(NAME double_parser COMMAND double_parses_test --test)