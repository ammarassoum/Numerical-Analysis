#include <stdio.h>

/**
 * Implements Richardson Extrapolation for Derivative Approximation.
 * 
 * @param f - Function pointer for the function to differentiate
 * @param x - Point at which to compute the derivative
 * @param h - Initial step size
 * @return Refined approximated derivative at x
 */
double richardson_extrapolation(double (*f)(double), double x, double h) {
    // D1: Central difference with step h
    double d1 = (f(x + h) - f(x - h)) / (2.0 * h);
    
    // D2: Central difference with step h/2
    double d2 = (f(x + h / 2.0) - f(x - h / 2.0)) / h;
    
    // Richardson extrapolation formula
    // Combining these cancels the O(h^2) error term
    return (4.0 * d2 - d1) / 3.0;
}

// --- Test the function ---

// Define the function: f(x) = x^2
double f_example(double x) {
    return x * x;
}

int main() {
    double x = 2.0;
    double h = 0.01;
    
    // Execute calculation
    double df = richardson_extrapolation(f_example, x, h);
    
    // Print the result with high precision
    printf("Richardson Extrapolation Result: %.10f\n", df);
    
    return 0;
}