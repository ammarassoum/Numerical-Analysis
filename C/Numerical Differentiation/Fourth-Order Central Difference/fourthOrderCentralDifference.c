#include <stdio.h>

/**
 * Implements Fourth-Order Central Difference for the first derivative.
 * 
 * @param f - Function pointer for the function to differentiate
 * @param x - Point at which to compute the derivative
 * @param h - Step size
 * @return Approximated derivative at x
 */
double fourth_order_central_difference(double (*f)(double), double x, double h) {
    // Formula: [-f(x+2h) + 8f(x+h) - 8f(x-h) + f(x-2h)] / (12h)
    double term1 = -f(x + 2.0 * h);
    double term2 = 8.0 * f(x + h);
    double term3 = -8.0 * f(x - h);
    double term4 = f(x - 2.0 * h);
    
    return (term1 + term2 + term3 + term4) / (12.0 * h);
}

// --- Test the function ---

// Define the function: f(x) = x^2
double f_example(double x) {
    return x * x;
}

int main() {
    double x = 2.0;
    double h = 0.01;
    
    // Execute the calculation
    double df = fourth_order_central_difference(f_example, x, h);
    
    // Print the result with high precision
    printf("Fourth-Order Central Difference Result: %.10f\n", df);
    
    return 0;
}