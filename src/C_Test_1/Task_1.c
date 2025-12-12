#include <stdio.h>

int main() {
    int n;
    printf("Введите число n: \n");
    scanf("%d", &n);
    char fib[n];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; ++i) {
        int temp_fib = fib[i - 2] + fib[i - 1];
        if (0 <= temp_fib && temp_fib <= 9) {
            fib[i] = temp_fib;
        }
        else {
            while (temp_fib > 0) {
                fib[i] = temp_fib % 10;
                temp_fib = temp_fib / 10;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            printf("%d ", fib[i]);
        }
        else {
            printf("%d ", fib[i]);
        }
    }
}