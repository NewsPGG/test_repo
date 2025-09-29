cmake_minimum_required(VERSION 4.0)
project(test_repo C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(test_repo
        src/C_homework_2/Task_1.c
        src/C_homework_2/Task_2.c
        src/C_homework_2/Task_3.c
        src/C_homework_2/Task_4.c)
