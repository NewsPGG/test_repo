cmake_minimum_required(VERSION 3.10)
project(C_Test_2)

add_executable(task2 Task1.c Task2.c List/List.c List/List.h)

enable_testing()
add_test(NAME Task2Test COMMAND task1 --test)