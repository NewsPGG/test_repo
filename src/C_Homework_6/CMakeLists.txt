cmake_minimum_required(VERSION 3.10)
project(Homework6)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(SortedList_c
        SortedList.c
)

add_executable(SortedList_h
        SortedList.h
)

add_executable(Task1
        Sorted_list.c
)

add_executable(Task2
        Counting_rhyme.c
)

target_include_directories(SortedList_c PRIVATE .)
target_include_directories(SortedList_h PUBLIC .)
target_include_directories(Task1 PRIVATE .)
target_include_directories(Task2 PRIVATE .)