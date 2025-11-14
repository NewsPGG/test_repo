cmake_minimum_required(VERSION 3.10)
project(SortedList)

# Основной исполняемый файл
add_executable(task1 Task1.c SortedList.c)

# Тестовый исполняемый файл
add_executable(test_sorted_list test_sorted_list.c SortedList.c)

# Добавляем тесты в ctest
enable_testing()
add_test(NAME SortedListTest COMMAND test_sorted_list --test)