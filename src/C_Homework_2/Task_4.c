#include <stdio.h>

int main()
{
    int counts[28] = {0};

    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                counts[a + b + c]++;
            }
        }
    }

    int happyTickets = 0;
    for (int s = 0; s <= 27; s++) {
        happyTickets += counts[s] * counts[s];
    }

    printf("%lld\n", happyTickets);
    return 0;
}