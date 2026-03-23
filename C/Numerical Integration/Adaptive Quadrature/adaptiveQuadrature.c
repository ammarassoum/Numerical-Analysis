#include <stdio.h>
#include <math.h>

/* 
 * Implements Adaptive Quadrature for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   tol - Error tolerance
 * Output:
 *   Returns the approximated integral value
 */
double adaptiveQuadrature(double (*f)(double), double a, double b, double tol) {
    double c = (a + b) / 2.0;
    
    // Single Simpson's rule over the whole interval
    double approx1 = (b - a) * (f(a) + 4.0 * f(c) + f(b)) / 6.0; 
    
    // Split interval: Simpson's rule on [a,c] and [c,b]
    double approx2 = ((c - a) * (f(a) + 4.0 * f((a + c) / 2.0) + f(c)) + 
                      (b - c) * (f(c) + 4.0 * f((c + b) / 2.0) + f(b))) / 6.0; 
    
    // Check if the difference is within the acceptable tolerance
    if (fabs(approx2 - approx1) < 15.0 * tol) {
        return approx2;
    } else {
        // Recursive call for both halves, with halved tolerance
        return adaptiveQuadrature(f, a, c, tol / 2.0) + adaptiveQuadrature(f, c, b, tol / 2.0);
    }
}

// Function to test: f(x) = x^2
double test_func(double x) {
    return x * x;
}

int main() {
    // Setup test parameters
    double a = 0.0;
    double b = 1.0;
    double tol = 1e-5;
    
    // Call the function
    double result = adaptiveQuadrature(test_func, a, b, tol);
    
    // Print the result
    printf("Adaptive Quadrature Result: %f\n", result);
    
    return 0;
}