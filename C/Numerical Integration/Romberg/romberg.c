#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Implements Romberg Integration for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   m - Maximum number of levels (rows/columns in Romberg matrix)
 * Output:
 *   Returns the approximated integral value
 */
double romberg(double (*f)(double), double a, double b, int m) {
    // Allocate a 1D array to act as an m x m matrix
    double *R = (double *)malloc(m * m * sizeof(double));
    
    // Macro for easy 2D indexing: R[row][col]
    #define R_idx(row, col) R[(row) * m + (col)]

    double h = b - a;
    
    // First estimate (Trapezoidal rule with 1 interval)
    R_idx(0, 0) = (h / 2.0) * (f(a) + f(b));
    
    for (int k = 1; k < m; k++) {
        h = h / 2.0;
        double summation = 0.0;
        
        // Calculate the number of new points to evaluate: 2^(k-1)
        int num_points = 1 << (k - 1); 
        
        for (int i = 0; i < num_points; i++) {
            // New evaluation points are at odd multiples of the new step size h
            double x = a + h + (i * 2.0 * h);
            summation += f(x);
        }
        
        // Recursive Trapezoidal rule
        R_idx(k, 0) = 0.5 * R_idx(k - 1, 0) + h * summation;
        
        // Richardson extrapolation for the rest of the row
        for (int j = 1; j <= k; j++) {
            double power_of_4 = pow(4.0, j);
            R_idx(k, j) = R_idx(k, j - 1) + (R_idx(k, j - 1) - R_idx(k - 1, j - 1)) / (power_of_4 - 1.0);
        }
    }
    
    // The most accurate approximation is at the bottom right of the calculated triangle
    double result = R_idx(m - 1, m - 1);
    
    // Free the allocated memory
    free(R);
    #undef R_idx
    
    return result;
}

// Function to test: f(x) = x^2
double test_func(double x) {
    return x * x;
}

int main() {
    // Setup test parameters
    double a = 0.0;
    double b = 1.0;
    int m = 4;
    
    // Calculate the integral
    double result = romberg(test_func, a, b, m);
    
    // Display the result (Expected: 0.333333)
    printf("Romberg Integration Result: %f\n", result);
    
    return 0;
}