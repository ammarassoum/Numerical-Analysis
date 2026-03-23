#include <stdio.h>
#include <stdlib.h>

/*
 * Function: forwardSubstitution
 * ----------------------------
 * Solves the system Lx = b for x using forward substitution.
 *
 * n : Dimension of the matrix (n x n)
 * L : Lower triangular matrix (flattened 1D array)
 * b : Right-hand side vector
 * x : Output solution vector
 */
void forwardSubstitution(int n, double *L, double *b, double *x) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        
        // Sum up the known values: L[i][j] * x[j]
        // Since L is lower triangular, we only go up to j < i
        for (int j = 0; j < i; j++) {
            sum += L[i * n + j] * x[j];
        }
        
        // Calculate the current x[i]
        // Check for division by zero (diagonal element)
        if (L[i * n + i] == 0) {
            printf("Error: Matrix is singular (zero on diagonal).\n");
            return;
        }
        
        x[i] = (b[i] - sum) / L[i * n + i];
    }
}

int main() {
    // --- Example Execution ---
    int n = 3;
    
    // Define Lower Triangular Matrix L (Row-major order)
    // 3, 0, 0
    // 2, 4, 0
    // 1, 2, 5
    double L[] = {
        3, 0, 0,
        2, 4, 0,
        1, 2, 5
    };
    
    double b[] = {6, 8, 10};
    double x[3]; // Array to hold the solution

    // Call the function
    forwardSubstitution(n, L, b, x);

    // Print results
    printf("Solution vector x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}