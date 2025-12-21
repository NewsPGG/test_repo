cmake_minimum_required(VERSION 3.10)
project(Homework2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Task1
        Task_1.c
)

add_executable(Task2
        Task_2.c
)

add_executable(Task3
        Task_3.c
)

add_executable(Task4
        Task_4.c
)

target_include_directories(Task1 PRIVATE .)
target_include_directories(Task2 PRIVATE .)
target_include_directories(Task3 PRIVATE .)
target_include_directories(Task4 PRIVATE .)