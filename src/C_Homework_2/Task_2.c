#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("Не делите на 0!!\n");
    }
    else {
        int check = 1;
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            check = -1;
        }
        a = abs(a);
        b = abs(b);

        int count = 0;
        while (a >= b) {
            a = a - b;
            count++;
        }

        printf("%d\n", count * check);
    }
}