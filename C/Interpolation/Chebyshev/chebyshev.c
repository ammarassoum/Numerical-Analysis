#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define M_PI if it's not defined in math.h (standard in many C environments)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * Function for Chebyshev Interpolation (Node Generation)
 * 
 * @param func  - Function pointer to the function to evaluate
 * @param n     - Number of Chebyshev points
 * @param a     - Start of interval
 * @param b     - End of interval
 * @param x_out - Pre-allocated array to store Chebyshev nodes
 * @param y_out - Pre-allocated array to store function values at nodes
 */
void chebyshev(double (*func)(double), int n, double a, double b, double *x_out, double *y_out) {
    for (int i = 0; i < n; i++) {
        // The index 'k' in the formula (2k-1) corresponds to (i+1) where i starts at 0
        // Formula: cos( (2k-1)*pi / (2n) )
        double k = i + 1.0;
        double cos_term = cos((2.0 * k - 1.0) * M_PI / (2.0 * n));
        
        // Map nodes from [-1, 1] to [a, b]
        x_out[i] = 0.5 * ((b - a) * cos_term + (b + a));
        
        // Evaluate function at the computed node
        y_out[i] = func(x_out[i]);
    }
}

// --- Test Case: Runge's Function ---
// f(x) = 1 / (1 + x^2)
double runge_function(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    int n = 10;
    double a = -5.0;
    double b = 5.0;

    // Allocate memory for nodes and values
    double *x_cheb = (double *)malloc(n * sizeof(double));
    double *y_cheb = (double *)malloc(n * sizeof(double));

    // Generate Chebyshev points
    chebyshev(runge_function, n, a, b, x_cheb, y_cheb);

    // Display Results
    printf("Chebyshev nodes and function values (n=%d, [%.1f, %.1f]):\n", n, a, b);
    printf("%-15s %-15s\n", "x_cheb", "y_cheb");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-15.6f %-15.6f\n", x_cheb[i], y_cheb[i]);
    }

    // Free memory
    free(x_cheb);
    free(y_cheb);

    return 0;
}