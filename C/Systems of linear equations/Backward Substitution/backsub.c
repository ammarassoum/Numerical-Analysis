#include <stdio.h>

/*
 * Function: backwardSubstitution
 * ------------------------------
 * Solves the system Ux = b using backward substitution.
 *
 * Parameters:
 *   n : Dimension of the system (n x n)
 *   U : Upper triangular matrix (flattened 1D array)
 *   b : Right-hand side vector
 *   x : Output solution vector
 */
void backwardSubstitution(int n, double *U, double *b, double *x) {
    // Start from the last row (n-1) and move upwards to the first row (0)
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;

        // Sum up the known values: U[i][j] * x[j]
        // Since U is upper triangular, we sum j from i+1 to n-1
        for (int j = i + 1; j < n; j++) {
            sum += U[i * n + j] * x[j];
        }

        // Check for diagonal zero (singular matrix)
        if (U[i * n + i] == 0) {
            printf("Error: Matrix is singular (zero on diagonal at index %d).\n", i);
            return;
        }

        // Calculate x[i]
        x[i] = (b[i] - sum) / U[i * n + i];
    }
}

int main() {
    // --- Example Execution ---
    int n = 3;

    // Define Upper Triangular Matrix U (Row-major order)
    // 2.0, 1.0, 1.0
    // 0.0, 2.0, 1.0
    // 0.0, 0.0, 1.0
    double U[] = {
        2.0, 1.0, 1.0,
        0.0, 2.0, 1.0,
        0.0, 0.0, 1.0
    };

    double b[] = {4.0, 2.0, 2.0};
    double x[3]; // Array to store the solution

    // Call the function
    backwardSubstitution(n, U, b, x);

    // Print the results
    printf("Solution vector x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}