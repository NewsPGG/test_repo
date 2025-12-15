#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkBracket(char open, char closed) {
    if ((open == '(' && closed == ')') || (open == '[' && closed == ']') || (open == '{' && closed == '}')) {
        return true;
    }
    return false;
}


int main() {
    struct Stack myStack = new();
    printf("Введите строку для проверки: \n");
    char symbols[100];
    scanf("%s", symbols);
    int lenght = strlen(symbols);

    for (int i = 0; i < lenght; ++i) {
        if (symbols[i] == '(' || symbols[i] == '[' || symbols[i] == '{') {
            push(&myStack, symbols[i]);
        }
        if (symbols[i] == ')' || symbols[i] == ']' || symbols[i] == '}') {
            if (checkBracket(peek(&myStack), symbols[i])) {
                pop(&myStack);
            }
        }
    }
    if (peek(&myStack) == -1) {
        printf("Баланс скобочек соблюдён! \n");
    } else {
        printf("Баланс скобочек не соблюдён (( \n");
    }
    delete(&myStack);
    return 0;
}