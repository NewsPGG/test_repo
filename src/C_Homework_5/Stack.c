#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack stack_new()
{
    struct Stack stack = {
        .head = NULL
    };
    return stack;
}

void stack_push(struct Stack* stack, int value)
{
    struct StackNode* node = malloc(sizeof(struct StackNode));
    node->value = value;
    node->next = stack->head;
    stack->head = node;
}

int stack_pop(struct Stack* stack)
{
    if (stack->head != NULL) {
        struct StackNode* oldNode = stack->head;
        int result = oldNode->value;
        stack->head = oldNode->next;
        free(oldNode);
        return result;
    } else {
        return -1;
    }
}

int stack_peek(struct Stack* stack)
{
    if (stack->head != NULL) {
        return stack->head->value;
    } else {
        return -1;
    }
}

void stack_delete(struct Stack* stack)
{
    while (stack->head != NULL) {
        stack_pop(stack);
    }
}