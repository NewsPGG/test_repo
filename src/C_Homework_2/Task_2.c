#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    if (b == 0) {
        printf("Не делите на 0!!\n");
    } else {
        int check = 1;
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            check = -1;
        }

        int abs_b = abs(b);
        int count = 0;

        while ((a < 0 ? -a : a) > abs_b || a < 0) {
            a = a - b * check;
            count++;
        }

        printf("%d\n", count * check);
    }
    return 0;
}