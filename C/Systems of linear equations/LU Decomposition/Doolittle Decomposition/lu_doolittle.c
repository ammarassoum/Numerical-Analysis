#include <stdio.h>
#include <stdlib.h>

void lu_decomposition(double **A, double **L, double **U, int n) {
    // Perform Doolittle LU decomposition of matrix A
    int i, j, k;
    double sum;

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i) {
                L[j][i] = 0;
            } else {
                L[j][i] = A[j][i];
                for (k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
            }
            if (j < i) {
                U[i][j] = 0;
            } else if (j == i) {
                U[i][j] = 1;
            } else {
                U[i][j] = A[i][j] / L[i][i];
                for (k = 0; k < i; k++) {
                    U[i][j] -= ((L[i][k] * U[k][j]) / L[i][i]);
                }
            }
        }
    }
}

int main() {
    // Example usage
    int n = 3, i, j;
    double **A, **L, **U;

    // Allocate memory for matrices
    A = (double**) malloc(n * sizeof(double*));
    L = (double**) malloc(n * sizeof(double*));
    U = (double**) malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        A[i] = (double*) malloc(n * sizeof(double));
        L[i] = (double*) malloc(n * sizeof(double));
        U[i] = (double*) malloc(n * sizeof(double));
    }

    // Define example input matrix
    A[0][0] = 4;
    A[0][1] = 6;
    A[0][2] = 10;
    A[1][0] = 6;
    A[1][1] = 25;
    A[1][2] = 19;
    A[2][0] = 10;
    A[2][1] = 19;
    A[2][2] = 62;

    // Perform LU decomposition
    lu_decomposition(A, L, U, n);

    // Print L and U matrices
    printf("L matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }
    printf("U matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);

    return 0;
}