#include "Stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Функция для расстановки приоритетов
int priority(char symbol) {
    if (symbol == '+' || symbol == '-') {
        return 1;
    }
    if (symbol == '*' || symbol == '/') {
        return 2;
    }
    return 0;
}

// Функция для проверки на операнд
bool operand(char symbol) {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
        return true;
    }
    return false;
}

void printExit(char array[], int size){
    for (int i = 0; i < size; i++){
        printf("%c" ,array[i]);
    }
    printf("\n");
}

int main()
{
    char sentence[50];
    printf("Введите выражение: \n");
    scanf("%[^\n]", sentence);
    int length = strlen(sentence);

    struct Stack oper = new();

    char exit[100];
    int sizeExit = 0;

    for (int i = 0; i < length; i++) {

        if (sentence[i] != ' ') {

            if (operand(sentence[i])) {
                char up = peek(&oper);

                // Выталкиваем элементы из стека
                // пока приоритет проверяемого символа не будет меньше приоритета верхнего элемента стека
                while ((up != -1) && (priority (sentence[i]) <= priority(up))) {
                    exit[sizeExit] = pop(&oper);
                    sizeExit++;
                    up = peek(&oper);
                }
                push(&oper, sentence[i]);

            } else {
                exit[sizeExit] = sentence[i];
                sizeExit++;
            }
        }
    }

    // Кладём в выходной массив оставшиеся в стеке операнды
    while (peek(&oper) != -1){
        exit[sizeExit] = pop(&oper);
        sizeExit++;
    }

    delete(&oper);
    printExit(exit, sizeExit);
    return 0;
}