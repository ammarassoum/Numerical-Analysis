#include <stdio.h>
#include <stdlib.h>

/* 
 * Implements Simpson's Rule for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   n - Number of subintervals (must be even)
 * Output:
 *   Returns the approximated integral value
 */
double simpson(double (*f)(double), double a, double b, int n) {
    // Check if n is even
    if (n % 2 != 0) {
        fprintf(stderr, "Error: n must be an even number for Simpson's rule.\n");
        exit(EXIT_FAILURE);
    }
    
    double h = (b - a) / n; // Width of each subinterval
    
    // Start the sum with the first and last terms: f(x_0) + f(x_n)
    double sum = f(a) + f(b);
    
    // Add the odd-indexed terms (multiplied by 4)
    for (int i = 1; i < n; i += 2) {
        sum += 4.0 * f(a + i * h);
    }
    
    // Add the even-indexed terms (multiplied by 2)
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2.0 * f(a + i * h);
    }
    
    // Finalize the Simpson's 1/3 rule formula
    return (h / 3.0) * sum;
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
    double result = simpson(test_func, a, b, n);
    
    // Display the result
    printf("Simpson's Rule Result: %f\n", result);
    
    return 0;
}