#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

void pop(void) {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void display(void) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main(void) {
    int choice, value;
    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
            case 1:
                printf("Value: ");
                if (scanf("%d", &value) != 1) return 1;
                push(value);
                break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
