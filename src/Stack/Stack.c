#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    struct stack *next;
} stack;

void push(stack *Stack, int value) {
    stack *elem = malloc(sizeof(stack));
    elem -> top = value;
    elem -> next = Stack -> next;
    Stack -> next = elem;
}

char pop(struct stack *stack) {
    return stack->top;
}

int peek(struct stack *stack) {
    return stack->top;
}

void new(struct stack *stack) {
    stack->top = 0;
}

void delete(struct stack *stack) {
    stack->top = 0;
}