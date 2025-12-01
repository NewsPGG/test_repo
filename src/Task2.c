#include <stdio.h>
#include "List/List.h"
#include "List/List.c"
#include <assert.h>

void enqueue(List *list, int value) {
    insertList(list, value);
}

void dequeue(List *list_front, List *list_rear) {
    for (int i = 0; i < 100; i++) {
        while (get(list_front, i)) {
            insertList(list_rear, i);
            removeList(list_front, i);
        }
    }
    printf("Лист: ");
    printList(list_rear);
}

void test_new_list() {
    List *list = newList();

    assert(list != NULL);
    assert(list->head == NULL);

    deleteList(list);
    printf("Тест 1: Выполнено\n");
}

void test_insert_one_element() {
    List *list1 = newList();
    List *list2 = newList();

    enqueue(list1, 1);
    dequeue(list1, list2);

    assert(get(list2, 1) == 1);
    printf("Тест 2: Выполнено\n");
}

void test_insert_many_elements() {
    List *list1 = newList();
    List *list2 = newList();

    enqueue(list1, 1);
    enqueue(list1, 2);
    enqueue(list1, 3);
    dequeue(list1, list2)

    assert(get(list2, 0) == 1);
    assert(get(list2, 1) == 2);
    assert(get(list2, 2) == 3);

    printf("Тест 3: Выполнено\n");
}

void test_insert_duplicates() {
    List *list1 = newList();
    List *list2 = newList();

    insertList(list1, 2);
    insertList(list1, 2);
    insertList(list1, 2);

    assert(get(list2, 0) == 2);
    assert(get(list2, 1) == 2);
    assert(get(list2, 2) == 2);

    printf("Тест 4: Выполнено\n");
}

int main() {
    List *front = newList();
    List *rear = newList();
    printList(front);
    printList(front);
}