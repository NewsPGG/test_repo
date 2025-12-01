#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int compare_binary_numbers(const bool number1[], int length1, const bool number2[], int length2) {
    if (length1 != length2) {
        if (length1 > length2) {
            return 1;
        } else {
            return -1;
        }
    }

    for (int i = 0; i < length1; i++) {
        if (number1[i] > number2[i]) {
            return 1;
        } else if (number1[i] < number2[i]) {
            return -1;
        }
    }
    return 0;
}

void print_result(const bool num1[], int len1, const bool num2[], int len2) {
    int result = compare_binary_numbers(num1, len1, num2, len2);

    if (result == 1) {
        printf("\nПервое число больше\n");
    } else if (result == -1) {
        printf("\nВторое число больше\n");
    } else {
        printf("\nЧисла равны\n");
    }
}

int main() {
    bool num1[1000];
    bool num2[1000];
    char a[1000];
    char b[1000];
    int len1 = 0, len2 = 0;

    printf("Введите первое число: \n");
    scanf("%s", a);

    printf("Введите второе число: \n");
    scanf("%s", b);

    len1 = strlen(a);
    for (int i = 0; i < len1; i++) {
        if (a[i] == '0') {
            num1[i] = false;
        } else if (a[i] == '1') {
            num1[i] = true;
        } else {
            printf("Введено что-то не то :)\n");
            return 1;
        }
    }

    len2 = strlen(b);
    for (int i = 0; i < len2; i++) {
        if (b[i] == '0') {
            num2[i] = false;
        } else if (b[i] == '1') {
            num2[i] = true;
        } else {
            printf("Введено что-то не то :)\n");
            return 1;
        }
    }

    print_result(num1, len1, num2, len2);
    return 0;
}