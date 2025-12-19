#include <stdio.h>

int bubble_sort(int *array, int size) {
    int flag = 1;
    int counter = 0;
    while (flag) {
        flag = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                counter++;
                flag = 1;
            }
        }
    }
    return counter;
}

int main() {
    int array[100];
    int size = 0;

    printf("Введите числа: ");
    while (scanf("%d", &array[size]) == 1 && size < 100) {
        size++;
    }

    int answer = bubble_sort(array, size);
    printf("%d", answer);
    return 0;
}
