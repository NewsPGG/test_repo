#include <stdio.h>

int main() {
    const int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int array[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            count++;
        }
     }

    printf("%d\n", count);

    return 0;
}