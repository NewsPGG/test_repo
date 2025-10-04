#include <stdio.h>

int main() {
    const int x;
    scanf("%d", &x);
    const int x2 = x * x; // Умножение 1
    const int sum = x2 * (x2 + x) + x2 + x + 1; // Умножение 2
    printf("%d\n", sum);
}