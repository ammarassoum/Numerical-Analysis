#include <stdio.h>

/**
 * Implements First-Order Forward Difference.
 * 
 * @param f - Function pointer for the function to differentiate
 * @param x - Point at which to compute the derivative
 * @param h - Step size
 * @return Approximated derivative at x
 */
double forward_difference(double (*f)(double), double x, double h) {
    // Formula: (f(x + h) - f(x)) / h
    return (f(x + h) - f(x)) / h;
}

// --- Test the function ---

// Define the function: f(x) = x^2
double f_example(double x) {
    return x * x;
}

int main() {
    double x = 2.0;
    double h = 0.01;
    
    // Execute the forward difference calculation
    double df = forward_difference(f_example, x, h);
    
    // Print the result
    printf("Forward Difference Result: %.5f\n", df);
    
    return 0;
}