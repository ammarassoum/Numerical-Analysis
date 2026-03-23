#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Function to solve Ax = b using Gauss-Seidel iteration
 * 
 * Inputs:
 *   n       - Dimension of the system
 *   A       - Coefficient matrix (flattened 1D array of size n*n)
 *   b       - Right-hand side vector (array of size n)
 *   x       - Output solution vector (array of size n)
 *   tol     - Convergence tolerance
 *   maxIter - Maximum number of iterations
 */
void gaussSeidel(int n, double *A, double *b, double *x, double tol, int maxIter) {
    // Initialize x to zeros
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Allocate memory for x_old to store previous iteration values
    double *x_old = (double *)malloc(n * sizeof(double));
    if (x_old == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int converged = 0; // Flag to track convergence

    for (int iter = 1; iter <= maxIter; iter++) {
        // Copy current x to x_old
        for (int i = 0; i < n; i++) {
            x_old[i] = x[i];
        }

        // Iteration over rows
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            // Iteration over columns
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    // Accessing A as a 1D array: row i, col j -> index i*n + j
                    sum += A[i * n + j] * x[j];
                }
            }
            // Update x[i]
            x[i] = (b[i] - sum) / A[i * n + i];
        }

        // Check for convergence (Infinity Norm of x - x_old)
        double max_diff = 0.0;
        for (int i = 0; i < n; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if (diff > max_diff) {
                max_diff = diff;
            }
        }

        if (max_diff < tol) {
            printf("Gauss-Seidel converged in %d iterations.\n", iter);
            converged = 1;
            break; // Exit loop
        }
    }

    if (!converged) {
        printf("Warning: Gauss-Seidel method did not converge within the maximum iterations.\n");
    }

    // Free dynamically allocated memory
    free(x_old);
}

int main() {
    // --- Test Data ---
    int n = 3;
    
    // Define A as a flattened array (row-major order)
    // Row 1: 4, -1, 0 | Row 2: -1, 4, -1 | Row 3: 0, -1, 4
    double A[] = {
         4, -1,  0,
        -1,  4, -1,
         0, -1,  4
    };
    
    double b[] = {15, 10, 10};
    double x[3]; // Array to hold the result
    
    double tol = 1e-5;
    int maxIter = 100;

    // Call the function
    gaussSeidel(n, A, b, x, tol, maxIter);

    // Display the results
    printf("Solution using Gauss-Seidel Method:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f\n", x[i]);
    }

    return 0;
}