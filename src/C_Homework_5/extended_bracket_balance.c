#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Все изменения описаны в комментариях
 * Не очень понял Ваш комментарий "open == closed ?" - это функция проверки,
 * соблюден ли баланс скобок на вершине стека (open) и текущего символа строки (closed)
 **/

bool checkBracket(char open, char closed)
{
    if ((open == '(' && closed == ')') ||
        (open == '[' && closed == ']') ||
        (open == '{' && closed == '}')) {
        return true;
    }
    return false;
}

int main()
{
    struct Stack myStack = new();
    printf("Введите строку для проверки: \n");
    char symbols[100];
    scanf("%s", symbols);
    int length = strlen(symbols);
    int count_not_bracket = 0; // Переменная для проверки, если ли скобки в строке
    bool error = false; // Переменная для отслеживания ошибок в работе алгоритма

    for (int i = 0; i < length; ++i) {
        if (symbols[i] == '(' || symbols[i] == '[' || symbols[i] == '{') {
            push(&myStack, symbols[i]);
        } else if (symbols[i] == ')' || symbols[i] == ']' || symbols[i] == '}') {
            // Если стек пустой и текущий символ - закрывающаяся скобка, меняем значение error
            if (peek(&myStack) == -1) {
                error = true;
                break;
            }
            if (checkBracket(peek(&myStack), symbols[i])) {
                pop(&myStack);
            // Если баланс скобок не соблюден, меняем значение error
            } else {
                error = true;
                break;
            }
            // Если текущий символ - не скобка, увеличиваем значение count_not_bracket
        } else {
            count_not_bracket++;
        }
    }

    // Если количество символов, не являющихся скобками, равно длине строки, то скобок нет
    if (count_not_bracket == length) {
        printf("Скобки не обнаружены!\n");
    } else if (error || peek(&myStack) != -1) {
        printf("Баланс скобочек не соблюдён ((\n");
    } else {
        printf("Баланс скобочек соблюдён!\n");
    }

    delete(&myStack);
    return 0;
}