#include <stdio.h>

/* 
 * Implements the Trapezoidal Rule for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   n - Number of subintervals
 * Output:
 *   Returns the approximated integral value
 */
double trapezoidal(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Width of each subinterval
    
    // Start with the boundary terms: 0.5 * f(a) + 0.5 * f(b)
    double sum = 0.5 * f(a) + 0.5 * f(b);
    
    // Add the interior points to the sum: sum(f(x_i))
    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        sum += f(x_i);
    }
    
    // Multiply by the width of the subintervals
    return h * sum;
}

// Function to test: f(x) = x^2
double test_func(double x) {
    return x * x;
}

int main() {
    // Setup test parameters
    double a = 0.0;
    double b = 1.0;
    int n = 10;
    
    // Calculate the integral
    double result = trapezoidal(test_func, a, b, n);
    
    // Display the result
    printf("Trapezoidal Rule Result: %f\n", result);
    
    return 0;
}