#include <stdio.h>

#define MAX 10

void read_matrix(int m[MAX][MAX], int r, int c, const char *name) {
    printf("Enter %s (%dx%d):\n", name, r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1) m[i][j] = 0;
}

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX] = {0};
    int r1, c1, r2, c2;

    printf("Rows and columns of matrix A: ");
    if (scanf("%d %d", &r1, &c1) != 2) return 1;
    printf("Rows and columns of matrix B: ");
    if (scanf("%d %d", &r2, &c2) != 2) return 1;

    if (c1 != r2) {
        printf("Cannot multiply: columns of A must equal rows of B.\n");
        return 1;
    }
    if (r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX || r1 < 1 || c1 < 1 || c2 < 1) {
        printf("Size must be between 1 and %d.\n", MAX);
        return 1;
    }

    read_matrix(a, r1, c1, "matrix A");
    read_matrix(b, r2, c2, "matrix B");

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];

    printf("Result:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) printf("%d\t", result[i][j]);
        printf("\n");
    }
    return 0;
}
