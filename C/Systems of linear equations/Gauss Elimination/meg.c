#include <stdio.h>

#define N 10 // Maximum size of the matrix

void gaussian_elimination(double a[N][N+1], int n);

int main() {
    int n; // Size of the matrix
    double a[N][N+1]; // Augmented matrix
    
    // Input the size of the matrix
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    // Input the elements of the augmented matrix
    printf("Enter the elements of the augmented matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    // Solve the system of equations using Gaussian elimination
    gaussian_elimination(a, n);
    
    // Output the solution vector
    printf("The solution vector is:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i+1, a[i][n]);
    }
    
    return 0;
}

void gaussian_elimination(double a[N][N+1], int n) {
    // Solves a system of linear equations using Gaussian elimination
    // Input: n x (n+1) augmented matrix a
    // Output: augmented matrix a in row echelon form
    
    // Forward elimination: convert the matrix to upper triangular form
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // Compute the ratio of the jth row to the ith row
            double ratio = a[j][i]/a[i][i];
            // Subtract the ith row multiplied by the ratio from the jth row
            for (int k = i; k < n+1; k++) {
                a[j][k] -= ratio*a[i][k];
            }
        }
    }
    
    // Backward substitution: solve for the variables starting from the last row
    for (int i = n-1; i >= 0; i--) {
        a[i][n] /= a[i][i];
        // Subtract the known variables from the ith equation
        for (int j = i-1; j >= 0; j--) {
            a[j][n] -= a[j][i]*a[i][n];
            a[j][i] = 0.0;
        }
    }
}