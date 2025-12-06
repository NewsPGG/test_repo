#include "double_parser.h"
#include <stdio.h>

DoubleComponents extract_double(double d) {
    DoubleBits db;
    db.value = d;

    DoubleComponents comp;
    comp.sign = (db.bits >> 63) & 1;
    comp.exponent = (db.bits >> 52) & 0x7FF;
    comp.mantissa = db.bits & 0xFFFFFFFFFFFFF;

    comp.is_zero = (comp.exponent == 0 && comp.mantissa == 0);
    comp.is_inf_nan = (comp.exponent == 0x7FF);
    comp.is_normal = (comp.exponent != 0);

    return comp;
}

int get_real_exponent(DoubleComponents comp) {
    if (comp.is_zero || !comp.is_normal) {
        return -1022;
    }
    return comp.exponent - 1023;
}

uint64_t get_full_mantissa(DoubleComponents comp) {
    if (comp.is_normal) {
        return comp.mantissa | (1ULL << 52);
    } else {
        return comp.mantissa;
    }
}

void print_mantissa(uint64_t full_mantissa) {
    printf("1.");
    
    uint64_t frac = full_mantissa & ((1ULL << 52) - 1);
    uint64_t remainder = frac;
    
    for (int i = 0; i < 20; i++) {
        remainder *= 10;
        int digit = remainder >> 52;
        printf("%d", digit);
        remainder &= (1ULL << 52) - 1;
        if (remainder == 0) break;
    }
}

void format_double(double number) {
    DoubleComponents comp = extract_double(number);

    if (comp.is_zero) {
        if (comp.sign) {
            printf("Результат: -0.0*2^-1022\n");
        } else {
            printf("Результат: +0.0*2^-1022\n");
        }
        return;
    }

    if (comp.is_inf_nan) {
        if (comp.mantissa == 0) {
            if (comp.sign) {
                printf("Результат: -inf\n");
            } else {
                printf("Результат: +inf\n");
            }
        } else {
            printf("Результат: NaN\n");
        }
        return;
    }

    int real_exponent = get_real_exponent(comp);
    uint64_t full_mantissa = get_full_mantissa(comp);

    printf("Результат: %c", comp.sign ? '-' : '+');
    print_mantissa(full_mantissa);
    printf("*2^%d\n", real_exponent);
}