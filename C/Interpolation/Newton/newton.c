#include <stdio.h>
#include <stdlib.h>

/*
 * Function: newtonInterpolation
 * -----------------------------
 * Performs Newton's Divided Difference Interpolation.
 *
 * Inputs:
 *   x        - The point to interpolate
 *   y_points - Array of known y values
 *   x_points - Array of known x values
 *   n        - Number of data points
 *
 * Returns:
 *   The interpolated value y at point x
 */
double newtonInterpolation(double x, double *y_points, double *x_points, int n) {
    // Allocate memory for the divided difference table (n x n flattened)
    double *diff_table = (double *)malloc(n * n * sizeof(double));
    if (diff_table == NULL) {
        printf("Memory allocation failed.\n");
        return 0.0;
    }

    // Initialize the first column with y_points
    for (int i = 0; i < n; i++) {
        diff_table[i * n + 0] = y_points[i];
    }

    // Construct the divided difference table
    // j represents the column index (order of difference)
    for (int j = 1; j < n; j++) {
        // i represents the row index
        for (int i = 0; i < n - j; i++) {
            // Calculate divided difference:
            // (Next Row, Prev Col) - (Curr Row, Prev Col) / (x[i+j] - x[i])
            double numerator = diff_table[(i + 1) * n + (j - 1)] - diff_table[i * n + (j - 1)];
            double denominator = x_points[i + j] - x_points[i];
            
            diff_table[i * n + j] = numerator / denominator;
        }
    }

    // Perform interpolation using the coefficients (top row of the table)
    double y = diff_table[0 * n + 0]; // First coefficient (b0)
    double product_term = 1.0;

    for (int i = 1; i < n; i++) {
        // Update product term: (x - x0)(x - x1)...
        product_term = product_term * (x - x_points[i - 1]);
        
        // Add term to result: product_term * coefficient
        y += product_term * diff_table[0 * n + i];
    }

    // Free allocated memory
    free(diff_table);

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
    
    // Calculate number of points
    int n = sizeof(x_points) / sizeof(x_points[0]);

    // Call the function
    double y = newtonInterpolation(x, y_points, x_points, n);

    // Display Result
    printf("Newton interpolation at x = %.2f: %.4f\n", x, y);

    return 0;
}