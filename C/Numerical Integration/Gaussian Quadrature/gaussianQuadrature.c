#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define Pi if it is not already defined by the compiler
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
 * Generates nodes and weights for Gaussian quadrature
 * Adapted from Numerical Recipes / Legendre Polynomials
 */
void lgwt(int n, double a, double b, double *x, double *w) {
    double *x_new = (double *)malloc(n * sizeof(double));
    double *dp = (double *)malloc(n * sizeof(double));
    
    // Initial guess using Chebyshev nodes approximation
    for (int i = 0; i < n; i++) {
        x[i] = cos(M_PI * (4.0 * (i + 1) - 1.0) / (4.0 * n + 2.0));
    }

    int max_iter = 100;
    double tol = 1e-14;

    // Newton's method loop
    for (int k = 0; k < max_iter; k++) {
        double max_diff = 0.0;

        for (int i = 0; i < n; i++) {
            double p0 = 0.0;
            double p1 = 1.0;
            double p2 = 0.0;

            // Evaluate Legendre polynomial up to degree n
            for (int j = 1; j <= n; j++) {
                p2 = p0;
                p0 = p1;
                p1 = ((2.0 * j - 1.0) * x[i] * p0 - (j - 1.0) * p2) / j;
            }

            // Derivative of the Legendre polynomial
            dp[i] = n * (p0 - x[i] * p1) / (1.0 - x[i] * x[i]);
            
            // Newton step
            x_new[i] = x[i] - p1 / dp[i];

            // Track maximum difference for convergence check
            double diff = fabs(x_new[i] - x[i]);
            if (diff > max_diff) {
                max_diff = diff;
            }
        }

        // Check if convergence tolerance is met
        if (max_diff < tol) {
            for (int i = 0; i < n; i++) {
                w[i] = 2.0 / ((1.0 - x[i] * x[i]) * dp[i] * dp[i]);
            }
            break;
        }

        // Update x for the next iteration
        for (int i = 0; i < n; i++) {
            x[i] = x_new[i];
        }
        
        // If maximum iterations are reached, calculate weights anyway
        if (k == max_iter - 1) {
            for (int i = 0; i < n; i++) {
                w[i] = 2.0 / ((1.0 - x[i] * x[i]) * dp[i] * dp[i]);
            }
        }
    }

    // Map the standard interval [-1, 1] to the specified interval [a, b]
    for (int i = 0; i < n; i++) {
        x[i] = (a + b) / 2.0 + (b - a) / 2.0 * x[i];
        w[i] = (b - a) / 2.0 * w[i];
    }

    // Free temporary memory
    free(x_new);
    free(dp);
}

/*
 * Implements n-point Gaussian Quadrature for numerical integration
 * Inputs:
 *   f - Function pointer
 *   a, b - Integration bounds
 *   n - Number of quadrature points
 * Output:
 *   Approximated integral value
 */
double gaussianQuadrature(double (*f)(double), double a, double b, int n) {
    // Allocate memory for nodes and weights
    double *nodes = (double *)malloc(n * sizeof(double));
    double *weights = (double *)malloc(n * sizeof(double));
    
    // Get nodes and weights
    lgwt(n, a, b, nodes, weights);
    
    double result = 0.0;
    // Summation of weights * f(nodes)
    for (int i = 0; i < n; i++) {
        result += weights[i] * f(nodes[i]);
    }
    
    // Cleanup memory
    free(nodes);
    free(weights);
    
    return result;
}

// Function to test: f(x) = x^2
double test_func(double x) {
    return x * x;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 3;
    
    double result = gaussianQuadrature(test_func, a, b, n);
    printf("Gaussian Quadrature Result: %f\n", result);
    
    return 0;
}