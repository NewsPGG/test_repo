#include <stdio.h>

void to_binary_twos_complement(int num, int binary[8]);
int add_binary_twos_complement(const int a_bin[8], const int b_bin[8], int sum_bin[8]);
int from_binary_twos_complement(const int binary[8]);

int main()
{
    // Тест 1
    printf("Тест 1: 5 + 6 = 11\n");
    int bin1[8], bin2[8], sum[8];

    to_binary_twos_complement(5, bin1);
    to_binary_twos_complement(6, bin2);
    add_binary_twos_complement(bin1, bin2, sum);
    int result = from_binary_twos_complement(sum);

    printf("Результат: %d\n", result);
    printf("Статус: %s\n\n", result == 11 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");

    // Тест 2
    printf("Тест 2: -5 + 2 = -3\n");

    to_binary_twos_complement(-5, bin1);
    to_binary_twos_complement(2, bin2);
    add_binary_twos_complement(bin1, bin2, sum);
    result = from_binary_twos_complement(sum);

    printf("Результат: %d\n", result);
    printf("Статус: %s\n\n", result == -3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");

    // Тест 3
    printf("Тест 3: -5 + (-7) = -13\n");

    to_binary_twos_complement(-5, bin1);
    to_binary_twos_complement(-7, bin2);
    add_binary_twos_complement(bin1, bin2, sum);
    result = from_binary_twos_complement(sum);

    printf("Результат: %d\n", result);
    printf("Статус: %s\n\n", result == -13 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");

    // Тест 4
    printf("Тест 4: 0 + 0 = 0\n");

    to_binary_twos_complement(0, bin1);
    to_binary_twos_complement(0, bin2);
    add_binary_twos_complement(bin1, bin2, sum);
    result = from_binary_twos_complement(sum);

    printf("Результат: %d\n", result);
    printf("Статус: %s\n\n", result == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");

    // Тест 5
    printf("Тест 5: Проверка преобразования 10 в двоичный вид\n");

    int binary[8];
    to_binary_twos_complement(10, binary);

    printf("Двоичное представление 10: ");
    for (int i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }

    int expected[8] = { 0, 0, 0, 0, 1, 0, 1, 0 };
    int correct = 1;
    for (int i = 0; i < 8; i++) {
        if (binary[i] != expected[i]) {
            correct = 0;
            break;
        }
    }

    printf("\nСтатус: %s\n\n", correct ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");

    return 0;
}
