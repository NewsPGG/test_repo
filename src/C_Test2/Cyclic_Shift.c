#include <stdbool.h>
#include <stdio.h>

void cyclicShift(bool numbers[], int n)
{
    if (n <= 1) {
        return;
    }

    bool last = numbers[n - 1];
    for (int i = n - 1; i > 0; i--) {
        numbers[i] = numbers[i - 1];
    }
    numbers[0] = last;
}

int binaryToDecimal(bool numbers[], int n)
{
    int decimal = 0;

    for (int i = 0; i < n; i++) {
        decimal = decimal * 2;
        if (numbers[i]) {
            decimal += 1;
        }
    }

    return decimal;
}

int main()
{
    int n;
    int size = 0;
    printf("Введите число N: ");
    scanf("%d", &n);
    bool numbers[n];

    printf("Введите двоичные цифры: ");
    while (scanf("%d", &numbers[size]) == 1 && size < n) {
        size++;
    }

    int maxDemical = binaryToDecimal(numbers, n);

    for (int i = 1; i < n; i++) {
        cyclicShift(numbers, n);
        int currentDemical = binaryToDecimal(numbers, n);
        if (currentDemical > maxDemical) {
            maxDemical = currentDemical;
        }
    }

    printf("Максимальное число: %d\n", maxDemical);
    return 0;
}