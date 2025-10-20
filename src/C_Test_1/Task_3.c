#include <stdio.h>

int binary_ss(int number) {
    if (number == 0) {
        return 0;
    }
    else if (number == 1) {
        return 1;
    }
    else {
        char elements[1000];
        int cnt = 0;
        while (number > 0) {
            elements[cnt] = number % 2;
            number = number / 2;
            ++cnt;
        }
        int count_1 = 0;
        for (int i = 0; i < 1000; ++i) {
            if (elements[i] == 1) {
                count_1++;
            }
        }
        return count_1;
    }
}

int main() {
    int size = 0;
    printf("Введите колвичество элементов: \n");
    scanf("%d", &size);
    int array[size];
    printf("Введите числа: \n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    int max_1 = 0;
    int temp = 0;
    for (int i = 0; i < size; ++i) {
        if (binary_ss(array[i]) > max_1) {
            max_1 = binary_ss(array[i]);
            temp = array[i];
        }
    }
    printf("Максимальное число в двоичной записи: \n");
    printf("%d", temp);
    return 0;
}