#include <stdio.h>
#include <string.h>

int main()
{
    char S[1000];
    printf("Введите строку: ");
    fgets(S, sizeof(S), stdin);

    int count = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '(') {
            count++;
        } else if (S[i] == ')') {
            if (count == 0) {
                printf("Баланс скобок не выполнен. WRONG!");
                return 0;
            }
            count--;
        }
    }

    if (count == 0) {
        printf("Баланс скобок выполнен!");
    }
    return 0;
}