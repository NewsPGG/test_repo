#include "SortedList.h"
#include "SortedList.c"
#include <stdio.h>

int main() {
    List *list = newList();
    int command;

    while (1) {
        printf("0 - Выход \n");
        printf("1 - Добавить элемент \n");
        printf("2 - Удалить элемент \n");
        printf("3 - Вывести список \n");
        printf("Выберите команду: ");
        scanf("%d", &command);

        switch (command) {
            case 0:
                deleteList(list);
                return 0;
            case 1: {
                int value;
                printf("Введите значение: ");
                scanf("%d", &value);
                insertList(list, value);
                break;
            }
            case 2: {
                int idx;
                printf("Введите индекс: ");
                scanf("%d", &idx);
                removeList(list, idx);
                break;
            }
            case 3:
                printList(list);
                break;
            default:
                printf("Неизвестная команда!\n");
        }
    }
    return 0;
}