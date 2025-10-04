#include <stdio.h>

int main() {
    int array[100], n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n + m; i++) {
        int value;
        scanf("%d", &value);
        array[i] = value;
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    for (int i = 0; i < (n + m) / 2; i++) {
        int value = array[i];
        array[i] = array[n + m - i - 1];
        array[n + m - i - 1] = value;
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}