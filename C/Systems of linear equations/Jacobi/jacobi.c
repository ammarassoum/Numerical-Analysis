#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Function to solve Ax = b using Jacobi iteration
 * 
 * Parameters:
 *   n       : Dimension of the matrix (n x n)
 *   A       : Coefficient matrix (flattened 1D array)
 *   b       : Right-hand side vector
 *   x       : Solution vector (output)
 *   tol     : Convergence tolerance
 *   maxIter : Maximum number of iterations
 */
void jacobi(int n, double *A, double *b, double *x, double tol, int maxIter) {
    // Allocate memory for the previous iteration vector (x_old)
    double *x_old = (double *)malloc(n * sizeof(double));
    if (x_old == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize x and x_old to zeros
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
        x_old[i] = 0.0;
    }

    int converged = 0; // Flag to track convergence

    for (int iter = 1; iter <= maxIter; iter++) {
        // Calculate the new x values based on x_old
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    // Access A[i, j] using row-major indexing: A[i*n + j]
                    sum += A[i * n + j] * x_old[j];
                }
            }
            // Update x[i]
            x[i] = (b[i] - sum) / A[i * n + i];
        }

        // Check for convergence (Infinity Norm: max absolute difference)
        double norm = 0.0;
        for (int i = 0; i < n; i++) {
            double diff = fabs(x[i] - x_old[i]);
            if (diff > norm) {
                norm = diff;
            }
        }

        if (norm < tol) {
            printf("Jacobi converged in %d iterations.\n", iter);
            converged = 1;
            break; // Stop iteration
        }

        // Update x_old for the next iteration
        for (int i = 0; i < n; i++) {
            x_old[i] = x[i];
        }
    }

    if (!converged) {
        printf("Warning: Jacobi method did not converge within the maximum iterations.\n");
    }

    // Free dynamically allocated memory
    free(x_old);
}

int main() {
    // --- Test Data ---
    int n = 3;
    
    // Matrix A defined as a 1D array
    // Row 0: 4, -1, 0 | Row 1: -1, 4, -1 | Row 2: 0, -1, 4
    double A[] = {
         4, -1,  0,
        -1,  4, -1,
         0, -1,  4
    };
    
    double b[] = {15, 10, 10};
    double x[3]; // Output vector
    double tol = 1e-5;
    int maxIter = 100;

    // Call the function
    jacobi(n, A, b, x, tol, maxIter);

    // Display the solution
    printf("Solution using Jacobi Method:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f\n", x[i]);
    }

    return 0;
}