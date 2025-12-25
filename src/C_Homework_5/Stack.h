#pragma once

struct StackNode {
    int value;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* head;
};

// Создание нового стека
struct Stack new();

// Положить элемент на стек
void push(struct Stack* stack, int value);

// Взять элемент со стека
int pop(struct Stack* stack);

// Посмотреть на вершину стека
int peek(struct Stack* stack);

// Удалить весь стек (освободить память)
void delete(struct Stack* stack);