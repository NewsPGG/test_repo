cmake_minimum_required(VERSION 3.10)

project(Task1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Task1 Task1.c)

add_executable(Task1_test test_task1.c)

target_include_directories(Task1_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(Task1 PRIVATE -Wall -Wextra)
target_compile_options(Task1_test PRIVATE -Wall -Wextra)

add_custom_target(test
        COMMAND Task1_test
)