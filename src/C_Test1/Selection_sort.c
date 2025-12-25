#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int elements;
    printf("Введите количесвто элементов: \n");
    scanf("%d", &elements);

    int array[elements];

    printf("Введите элементы: \n");
    for (int i = 0; i < elements; ++i) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < elements - 1; ++i) {
        int min = array[i];
        int temp = i;
        for (int j = i + 1; j < elements; ++j) {
            if (array[j] < min) {
                min = array[j];
                temp = j;
            }
        }
        swap(&array[i], &array[temp]);
        for (int j = 0; j < elements; ++j) {
            printf("%d ", array[j]);
        }
        printf("\n");
    }

    printf("Отсортированный массив: ");
    for (int i = 0; i < elements; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}