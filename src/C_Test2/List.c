#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

List* newList()
{
    List* list = calloc(1,sizeof(List));
    list->head = NULL;
    return list;
}

void appendList(List* list, int value)
{
    if (list == NULL) {
        return;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    ListNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

bool symmetricList(List* list)
{
    if (list == NULL || list->head == NULL) {
        return true;
    }

    int arr[1000];
    int n = 0;
    ListNode* current = list->head;

    while (current != NULL) {
        arr[n] = current->value;
        n++;
        current = current->next;
    }

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }

    return true;
}

void printList(List* list)
{
    if (list == NULL || list->head == NULL) {
        printf("Список пуст!\n");
        return;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void freeList(List* list)
{
    if (list == NULL) {
        return;
    }

    ListNode* current = list->head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}