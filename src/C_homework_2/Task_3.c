#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int m = 3, n = 5; // Такие числа в качестве примера
    int array1[m], array2[n];
    for (int i = 0; i < m; i++) {
        array1[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        array2[i] = i + 4;
    }
    printf("Before sorting, array1:\n");
    for (int i = 0; i < m; i++) {
        printf("%d\n", array1[i]);
    }
    printf("Before sorting, array2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", array2[i]);
    }

    if (m <= n) {
        for (int i = 0; i < m; i++) {
            swap(array1[i], array2[i]);
        }

    }
    printf("After sorting, array1:\n");
    for (int i = 0; i < m; i++) {
        printf("%d\n", array1[i]);
    }
    printf("After sorting, array2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", array2[i]);
    }
}
