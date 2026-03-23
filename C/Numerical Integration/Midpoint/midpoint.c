#include <stdio.h>

/* 
 * Implements the Midpoint Rule for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   n - Number of subintervals
 * Output:
 *   Returns the approximated integral value
 */
double midpoint(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // Width of each subinterval
    double sum = 0.0;
    
    // Iterate through each subinterval
    for (int i = 0; i < n; i++) {
        // Calculate the midpoint of the current subinterval
        double mid = a + (h / 2.0) + (i * h);
        
        // Evaluate the function at the midpoint and add to the sum
        sum += f(mid);
    }
    
    // Multiply the sum of the heights by the width of the subintervals
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
    double result = midpoint(test_func, a, b, n);
    
    // Display the result
    printf("Midpoint Rule Result: %f\n", result);
    
    return 0;
}