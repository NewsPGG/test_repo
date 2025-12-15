cmake_minimum_required(VERSION 3.10)
project(StackProjects)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(SortedList
    Sorted_List.c
    SortedList.c
)

target_include_directories(SortedList PRIVATE .)

enable_testing()
add_test(NAME SortedListTest COMMAND Tests_to_sorted_list --test)