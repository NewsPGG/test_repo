#include <stdio.h>

void coup(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int array[1000], n, m;
    printf("Введите числа n и m: \n");
    scanf("%d %d", &n, &m);

    printf("Введите числа массива: \n");
    for (int i = 0; i < n + m; i++) {
        int value;
        scanf("%d", &value);
        array[i] = value;
    }

    printf("Исходный массив: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    coup(array, 0, n - 1);
    coup(array, n, n + m - 1);
    coup(array, 0, n + m - 1);

    printf("Новый массив: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}