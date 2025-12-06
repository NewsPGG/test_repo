#include <stdio.h>

void to_binary_twos_complement(int num, int binary[8]) {
    char char_num = num;

    for (int i = 7; i >= 0; i--) {
        binary[7 - i] = (char_num >> i) & 1;
    }
}

int add_binary_twos_complement(const int a_bin[8], const int b_bin[8],
                               int sum_bin[8]) {
    int carry = 0;

    for (int i = 7; i >= 0; i--) {
        int s = a_bin[i] + b_bin[i] + carry;
        sum_bin[i] = s % 2;
        carry = s / 2;
    }

    return carry;
}

int from_binary_twos_complement(const int binary[8]) {
    char result = 0;

    for (int i = 0; i < 8; i++) {
        result = (result << 1) | binary[i];
    }

    return (int)result;
}

void print_binary(const int binary[8]) {
    for (int i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
}

int main() {
    int number1, number2;
    int bin_number1[8], bin_number2[8], bin_summ[8];
    int summ;

    printf("Введите первое число: ");
    scanf("%d", &number1);
    printf("Введите второе число: ");
    scanf("%d", &number2);

    to_binary_twos_complement(number1, bin_number1);
    to_binary_twos_complement(number2, bin_number2);

    printf("\nДвоичное представление: \n");
    printf("%d = ", number1);
    print_binary(bin_number1);

    printf("\n%d = ", number2);
    print_binary(bin_number2);

    printf("\nРезультат сложения: ");
    print_binary(bin_summ);

    summ = from_binary_twos_complement(bin_summ);

    printf("\nВ десятичном виде: %d\n", summ);

    return 0;
}
