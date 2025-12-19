#pragma once
#include <stdbool.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

List* newList();

void appendList(List* list, int value);

bool symmetricList(List* list);

void printList(List* list);

void freeList(List* list);