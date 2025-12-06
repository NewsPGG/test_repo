#include "double_parser.h"
#include <stdio.h>

int main() {
    double number;
    printf("Введите число: ");
    scanf("%lf", &number);

    format_double(number);
    return 0;
}