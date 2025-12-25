#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int pos;
    struct Node* next;
} Node;

Node* create_node(int pos)
{
    Node* new = malloc(sizeof(Node));
    new->pos = pos;
    new->next = NULL;
    return new;
}

Node* create_circle(int n)
{
    Node* head = create_node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        Node* new_node = create_node(i);
        current->next = new_node;
        current = new_node;
    }

    current->next = head;
    return head;
}

int main()
{
    int n, m;
    printf("Введите числа n и m: ");
    scanf("%d %d", &n, &m);

    Node* head = create_circle(n);
    Node* current = head;
    Node* prev = NULL;

    while (current->next != current) {
        for (int i = 1; i < m; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        Node* to_delete = current;
        current = current->next;
        free(to_delete);
    }

    printf("Ответ: %d\n", current->pos);
    free(current);
    return 0;
}