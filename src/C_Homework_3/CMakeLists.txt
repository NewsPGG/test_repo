cmake_minimum_required(VERSION 3.10)
project(Task_1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Task_1 Task_1.c)
add_executable(Task_2 Task_2.c)
add_executable(Task_3 Task_3.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)