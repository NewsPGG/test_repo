#include "SortedList.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_new_list()
{
    List* list = newList();

    assert(list != NULL);
    assert(list->head == NULL);

    deleteList(list);
    printf("Тест 1: Выполнено\n");
}

void test_insert_into_empty_list()
{
    List* list = newList();

    assert(insertList(list, 5) == true);
    assert(list->head != NULL);
    assert(list->head->value == 5);
    assert(list->head->next == NULL);

    deleteList(list);
    printf("Тест 2: Выполнено\n");
}

void test_insert_sorted_order()
{
    List* list = newList();

    insertList(list, 3);
    insertList(list, 2);
    insertList(list, 1);

    assert(get(list, 0) == 1);
    assert(get(list, 1) == 2);
    assert(get(list, 2) == 3);

    deleteList(list);
    printf("Тест 3: Выполнено\n");
}

void test_insert_duplicates()
{
    List* list = newList();

    insertList(list, 2);
    insertList(list, 2);
    insertList(list, 2);

    assert(get(list, 0) == 2);
    assert(get(list, 1) == 2);
    assert(get(list, 2) == 2);
    assert(get(list, 3) == -1);

    deleteList(list);
    printf("Тест 4: Выполнено\n");
}

void test_remove_from_empty_list()
{
    List* list = newList();

    assert(removeList(list, 0) == false);
    assert(removeList(list, -1) == false);
    assert(removeList(list, 5) == false);

    deleteList(list);
    printf("Тест 5: Выполнено\n");
}

void test_remove_first_element()
{
    List* list = newList();

    insertList(list, 1);
    insertList(list, 2);
    insertList(list, 3);

    assert(removeList(list, 0) == true);
    assert(get(list, 0) == 2);
    assert(get(list, 1) == 3);
    assert(get(list, 2) == -1);

    deleteList(list);
    printf("Тест 6: Выполнено\n");
}

void test_remove_middle_element()
{
    List* list = newList();

    insertList(list, 1);
    insertList(list, 2);
    insertList(list, 3);

    assert(removeList(list, 1) == true);
    assert(get(list, 0) == 1);
    assert(get(list, 1) == 3);
    assert(get(list, 2) == -1);

    deleteList(list);
    printf("Тест 7: Выполнено\n");
}

void test_remove_last_element()
{
    List* list = newList();

    insertList(list, 1);
    insertList(list, 2);
    insertList(list, 3);

    assert(removeList(list, 2) == true);
    assert(get(list, 0) == 1);
    assert(get(list, 1) == 2);
    assert(get(list, 2) == -1);

    deleteList(list);
    printf("Тест 8: Выполнено\n");
}

void test_remove_invalid_index()
{
    List* list = newList();

    insertList(list, 1);
    insertList(list, 2);

    assert(removeList(list, -1) == false);
    assert(removeList(list, 5) == false);
    assert(get(list, 0) == 1);
    assert(get(list, 1) == 2);

    deleteList(list);
    printf("Тест 9: Выполнено\n");
}

void test_get_from_empty_list()
{
    List* list = newList();

    assert(get(list, 0) == -1);
    assert(get(list, -1) == -1);
    assert(get(list, 5) == -1);

    deleteList(list);
    printf("Тест 10: Выполнено\n");
}

void test_get_invalid_index()
{
    List* list = newList();

    insertList(list, 1);
    insertList(list, 2);
    insertList(list, 3);

    assert(get(list, -1) == -1);
    assert(get(list, 5) == -1);

    deleteList(list);
    printf("Тест 11: Выполнено\n");
}

void test_insert_get_list()
{
    List* list = newList();

    for (int i = 50; i >= 0; i--) {
        assert(insertList(list, i) == true);
    }

    for (int i = 0; i <= 50; i++) {
        assert(get(list, i) == i);
    }

    deleteList(list);
    printf("Тест 12: Выполнено\n");
}

void test_delete_null_list()
{
    assert(deleteList(NULL) == false);
    printf("Тест 13: Выполнено\n");
}

void test_insert_null_list()
{
    assert(insertList(NULL, 10) == false);
    printf("Тест 14: Выполнено\n");
}

void test_remove_null_list()
{
    assert(removeList(NULL, 0) == false);
    printf("Тест 15: Выполнено\n");
}

void test_get_null_list()
{
    assert(get(NULL, 0) == -1);
    printf("Тест 16: Выполнено\n");
}

void run_all_tests()
{
    test_new_list();
    test_insert_into_empty_list();
    test_insert_sorted_order();
    test_insert_duplicates();
    test_remove_from_empty_list();
    test_remove_first_element();
    test_remove_middle_element();
    test_remove_last_element();
    test_remove_invalid_index();
    test_get_from_empty_list();
    test_get_invalid_index();
    test_insert_get_list();
    test_delete_null_list();
    test_insert_null_list();
    test_remove_null_list();
    test_get_null_list();

    printf("Все тесты завершены успешно!\n");
}

int main(int argc, char* argv[])
{
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        run_all_tests();
        return 0;
    }
}