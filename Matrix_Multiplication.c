#include <stdio.h>
#include <stdlib.h>

int** makeMatrix(int rows, int cols) {
    int **mat = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

void readMatrix(int **mat, int rows, int cols) {
    printf("Enter %d x %d matrix elements:\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

int** multiply(int **a, int **b, int r1, int c1, int c2) {
    int **res = makeMatrix(r1, c2);
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void freeMatrix(int **mat, int rows) {
    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and cols for Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and cols for Matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Can't multiply. Columns of A must match rows of B.\n");
        return 1;
    }

    int **a = makeMatrix(r1, c1);
    int **b = makeMatrix(r2, c2);

    printf("\nMatrix A:\n");
    readMatrix(a, r1, c1);

    printf("\nMatrix B:\n");
    readMatrix(b, r2, c2);

    int **c = multiply(a, b, r1, c1, c2);

    printf("\nResult (A x B):\n");
    printMatrix(c, r1, c2);

    freeMatrix(a, r1);
    freeMatrix(b, r2);
    freeMatrix(c, r1);

    return 0;
}
