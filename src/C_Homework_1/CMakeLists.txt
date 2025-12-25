cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(Task_1
        Task_1.c
)

target_include_directories(Task_1 PRIVATE .)