#include "List.h"
#include "stdio.h"

int main()
{
    List* list = newList();

    int number;
    printf("Введите числа: ");
    while (scanf("%d", &number) == 1) {
        appendList(list, number);
    }

    printf("Ваш список: ");
    printList(list);

    if (symmetricList(list)) {
        printf("Список симметричен\n");
    } else {
        printf("Список не симметричен\n");
    }

    freeList(list);
    return 0;
}
