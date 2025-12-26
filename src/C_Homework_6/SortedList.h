#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

// Создание нового списка
List* newList();

// Добавление элемента в список
bool insertList(List* list, int value);

// Удалить элемент из списка по индексу
bool removeList(List* list, int index);

// Вывести элемент из списка по индексу
int get(List* list, int index);

// Вывести весь список
void printList(List* list);

// Удалить список, освободить память
bool deleteList(List* list);