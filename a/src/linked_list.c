#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insert_end(Node *head, int value) {
    Node *n = malloc(sizeof *n);
    if (!n) {
        printf("Memory allocation failed\n");
        return head;
    }
    n->data = value;
    n->next = NULL;
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node *delete_value(Node *head, int value) {
    Node *cur = head, *prev = NULL;
    while (cur && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("%d not found\n", value);
        return head;
    }
    if (prev) prev->next = cur->next;
    else head = cur->next;
    free(cur);
    return head;
}

void display(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) printf("%d -> ", cur->data);
    printf("NULL\n");
}

void free_list(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    Node *head = NULL;
    for (int i = 1; i <= 5; i++) head = insert_end(head, i * 10);

    printf("Initial list: ");
    display(head);

    head = delete_value(head, 30);
    printf("After deleting 30: ");
    display(head);

    head = delete_value(head, 99);

    free_list(head);
    return 0;
}
