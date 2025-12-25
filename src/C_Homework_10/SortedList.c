#include "SortedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List* newList()
{
    List* list = calloc(1, sizeof(List));
    list->head = NULL;
    return list;
}

bool insertList(List* list, int value)
{
    if (list == NULL) {
        return false;
    }

    ListNode* newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return false;
    }
    newNode->value = value;
    newNode->next = NULL;

    if ((list->head == NULL) || (value <= list->head->value)) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }

    ListNode* current = list->head;
    while ((current->next != NULL) && (current->next->value < value)) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool removeList(List* list, int index)
{
    if (index < 0 || list == NULL || list->head == NULL) {
        return false;
    }

    if (index == 0) {
        ListNode* popNode = list->head;
        list->head = popNode->next;
        free(popNode);
        return true;
    }
    ListNode* current = list->head;
    int idx = 0;
    while ((current != NULL) && (current->next != NULL)) {
        if (idx == index - 1) {
            ListNode* popNode = current->next;
            current->next = popNode->next;
            free(popNode);
            return true;
        }
        current = current->next;
        idx++;
    }
    return false;
}

int get(List* list, int index)
{
    if (list == NULL || list->head == NULL || index < 0) {
        return -1;
    }
    ListNode* current = list->head;
    int idx = 0;
    while (current != NULL) {
        if (index == idx) {
            return current->value;
        }
        current = current->next;
        idx++;
    }
    return -1;
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

bool deleteList(List* list)
{
    if (list == NULL) {
        return false;
    }
    while (list->head != NULL) {
        removeList(list, 0);
    }
    free(list);
    return true;
}