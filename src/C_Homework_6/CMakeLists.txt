cmake_minimum_required(VERSION 3.10)
project(Homework6)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(SortedList
        Sorted_List.c
        SortedList.c
)

add_executable(Counting_rhyme
        Counting_rhyme.c
)

target_include_directories(SortedList PRIVATE .)
target_include_directories(Counting_rhyme PRIVATE .)