#include "Stack.c"

int main() {
    struct stack stack_1;
    new(&stack_1);

    for (int i = 0; i < 10; i++) {
        push(&stack_1, i);
    }

    for (int i = 0; i < 10; i++) {
        pop(&stack_1, i);
        printf("%d\n", peek(&stack_1));
    }
    return 0;
}