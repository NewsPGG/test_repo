#include <stdio.h>

int multiplication(int number)
{
    int number2 = number * number; // Умножение 1
    int sum = number2 * (number2 + number) + number2 + number + 1; // Умножение 2
    return sum;
}

int main() {
    int x;
    printf("Введите x: ");
    scanf("%d", &x);
    int result = multiplication(x);
    printf("%d\n", result);

    return 0;
}