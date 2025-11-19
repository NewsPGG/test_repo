#include <stdio.h>
#include <string.h>

int check(const char* S, const char* S1)
{
    int count = 0;
    int lenS = strlen(S);
    int lenS1 = strlen(S1);

    for (int i = 0; i <= lenS - lenS1; i++) {
        if (strncmp(&S[i], S1, lenS1) == 0) {
            count++;
        }
    }
    return count;
}

int main()
{
    char S[1000], S1[1000];

    printf("Введите строку S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = '\0'; // Удаляем символ новой строки

    printf("Введите строку S1: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = '\0'; // Удаляем символ новой строки

    int value = check(S, S1);
    printf("Количество вхождений подстроки S1 в строку S: %d\n", value);

    return 0;
}