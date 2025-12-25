#pragma once

struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

// Создание нового стека
struct Stack stack_new();

// Положить элемент на стек
void stack_push(struct Stack* stack, int value);

// Взять элемент со стека
int stack_pop(struct Stack* stack);

// Посмотреть на вершину стека
int stack_peek(struct Stack* stack);

// Удалить весь стек (освободить память)
void stack_delete(struct Stack* stack);