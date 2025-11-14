#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Stack.c"

int get_priority(char operation) {
    switch (operation) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}

int main() {
    struct Stack Operations = new();
    char input[100];
    char output[100] = "";
    int output_index = 0;
    int stack_size = 0;

    printf("Введите выражение (без пробелов!): ");
    scanf("%s", input);

    int length = strlen(input);

    for (int i = 0; i < length; ++i) {
        char current = input[i];

        if (isdigit(current)) {
            output[output_index++] = current;
            output[output_index++] = ' ';
        }
        else if (current == '(') {
            push(&Operations, current);
            stack_size++;
        }
        else if (current == ')') {
            while (stack_size > 0) {
                char top_char = pop(&Operations);
                stack_size--;
                if (top_char == '(')
                    break;
                output[output_index++] = top_char;
                output[output_index++] = ' ';
            }
        }
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (stack_size > 0) {
                char top_char = pop(&Operations);
                if (top_char == '(' || get_priority(top_char) < get_priority(current)) {
                    push(&Operations, top_char);
                    break;
                }
                stack_size--;
                output[output_index++] = top_char;
                output[output_index++] = ' ';
            }
            push(&Operations, current);
            stack_size++;
        }
    }

    while (stack_size > 0) {
        output[output_index++] = pop(&Operations);
        output[output_index++] = ' ';
        stack_size--;
    }

    if (output_index > 0) {
        output[output_index - 1] = '\0';
    }

    printf("Преобразованная запись: %s\n", output);

    return 0;
}