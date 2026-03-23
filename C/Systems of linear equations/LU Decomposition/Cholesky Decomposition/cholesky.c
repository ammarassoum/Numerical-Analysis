#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cholesky(double **A, double **L, int n) {
    int i, j, k;
    double sum;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            sum = 0;
            if (j == i) {
                for (k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (k = 0; k < j; k++) {
                    sum += L[i][k]*L[j][k];
                }
                L[i][j] = (A[i][j] - sum)/L[j][j];
            }
        }
    }
}

int main() {
    int i, j, n;
    double **A, **L;
    
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    A = (double **)malloc(n * sizeof(double *));
    L = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
    }
    
    printf("Enter the matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    
    cholesky(A, L, n);
    
    printf("L:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}