#include <stdio.h>

#define N 10 // Maximum size of the matrix

void crout_lu(double a[N][N], double l[N][N], double u[N][N], int n);

int main() {
    int n; // Size of the matrix
    double a[N][N]; // Input matrix
    double l[N][N]; // Lower triangular matrix
    double u[N][N]; // Upper triangular matrix
    
    // Input the size of the matrix
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    // Perform Crout LU decomposition
    crout_lu(a, l, u, n);
    
    // Output the lower and upper triangular matrices
    printf("Lower triangular matrix L:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", l[i][j]);
        }
        printf("\n");
    }
    
    printf("Upper triangular matrix U:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", u[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void crout_lu(double a[N][N], double l[N][N], double u[N][N], int n) {
    // Performs Crout LU decomposition on a square matrix a
    // Input: n x n matrix a
    // Output: n x n lower triangular matrix l, n x n upper triangular matrix u
    
    // Initialize the diagonal elements of L to 1
    for (int i = 0; i < n; i++) {
        l[i][i] = 1.0;
    }
    
    // Compute the elements of L and U
    for (int j = 0; j < n; j++) {
        // Compute the jth column of U
        for (int i = j; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += l[i][k]*u[k][j];
            }
            u[i][j] = a[i][j] - sum;
        }
        
        // Compute the jth row of L
        for (int i = j+1; i < n; i++) {
            double sum = 0.0;
            for (int k = 0; k < j; k++) {
                sum += l[j][k]*u[k][i];
            }
            l[j][i] = (a[j][i] - sum)/u[j][j];
        }
    }
}