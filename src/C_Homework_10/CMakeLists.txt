cmake_minimum_required(VERSION 3.10)
project(double_parser)

add_library(double_parser_lib double_parser.c)

add_executable(main main.c)
target_link_libraries(main double_parser_lib m)

add_executable(test test.c)
target_link_libraries(test double_parser_lib m)