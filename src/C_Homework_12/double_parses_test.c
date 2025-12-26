#include "double_parser.h"
#include <math.h>
#include <stdio.h>

int main()
{
    // Тест 1: -2.5
    printf("Тест -2.5:\n");
    format_double(-2.5);
    printf("Ожидалось: -1.25*2^1\n\n");

    // Тест 2: 1.0
    printf("Тест 1.0:\n");
    format_double(1.0);
    printf("Ожидалось: +1.0*2^0\n\n");

    // Тест 3: 0.0
    printf("Тест 0.0:\n");
    format_double(0.0);
    printf("Ожидалось: +0.0*2^-1022\n\n");

    // Тест 4: бесконечность
    printf("Тест INFINITY:\n");
    format_double(INFINITY);
    printf("Ожидалось: +inf\n\n");

    // Тест 5: 12312.323
    printf("Тест 12312.323:\n");
    format_double(12312.323);
    printf("Ожидалось: +1.5029691162109375384*2^13\n\n");

    return 0;
}
