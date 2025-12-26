#include "sort.h"
#include <stdio.h>

int main()
{
    int array[100];
    int size = 0;

    printf("Введите числа: ");
    while (scanf("%d", &array[size]) == 1 && size < 100) {
        size++;
    }

    int answer = bubble_sort(array, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return answer;
}
