#pragma once

#include <stdint.h>

typedef union DoubleBits {
    double value;
    uint64_t bits;
} DoubleBits;

typedef struct DoubleComponents {
    int sign;
    uint64_t mantissa;
    int exponent;
    int is_normal;
    int is_zero;
    int is_inf_nan;
} DoubleComponents;

DoubleComponents extract_double(double d);
int get_real_exponent(DoubleComponents comp);
uint64_t get_full_mantissa(DoubleComponents comp);
void print_mantissa(uint64_t full_mantissa);
void format_double(double number);
