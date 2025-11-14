cmake_minimum_required(VERSION 3.25)
project(Task7 LANGUAGES C)

# Сборка Stack
add_library(stack STATIC Stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Сборка bracket_balance
add_executable(bracket_balance Task1.c)
target_link_libraries(bracket_balance PRIVATE stack)

# Сборка sort_station
add_executable(sort_station Task2.c)
target_link_libraries(sort_station PRIVATE stack)