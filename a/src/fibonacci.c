#include <stdio.h>

int main(void) {
    int n;
    printf("How many terms? ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 90) {
        printf("Enter a number between 1 and 90.\n");
        return 1;
    }

    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        long long next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
