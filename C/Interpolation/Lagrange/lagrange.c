#include <stdio.h>
#include <stdlib.h>

/**
 * Function for Lagrange Interpolation
 * 
 * Inputs:
 *   x        - The point to interpolate
 *   y_points - Array of known Y values
 *   x_points - Array of known X values
 *   n        - Number of data points
 * 
 * Returns:
 *   The interpolated value y at point x
 */
double lagrange(double x, double *y_points, double *x_points, int n) {
    double y = 0.0; // Initialize result

    // Outer loop: Summation of L_i(x) * y_i
    for (int i = 0; i < n; i++) {
        
        // Initialize Lagrange basis polynomial L_i(x)
        double L = 1.0;

        // Inner loop: Product sequence for L_i(x)
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Calculate product term: (x - x_j) / (x_i - x_j)
                L = L * (x - x_points[j]) / (x_points[i] - x_points[j]);
            }
        }

        // Add the term to the final polynomial value
        y = y + L * y_points[i];
    }

    return y;
}

int main() {
    // --- Test Data ---
    // x_points = [0, 1, 2]
    double x_points[] = {0.0, 1.0, 2.0};
    
    // y_points = [1, 3, 2]
    double y_points[] = {1.0, 3.0, 2.0};
    
    // Point to interpolate
    double x = 1.5;
    
    // Calculate size of array
    int n = sizeof(x_points) / sizeof(x_points[0]);

    // Call the function
    // Note: Arguments match the requested signature logic 
    // (x, y_points, x_points, size)
    double result = lagrange(x, y_points, x_points, n);

    // Display Result
    printf("Lagrange interpolation at x = %.2f: %.4f\n", x, result);

    return 0;
}