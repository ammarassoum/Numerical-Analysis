#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
 * Implements Monte Carlo Integration for numerical integration
 * Inputs:
 *   f - Function pointer to the integrand
 *   a, b - Integration bounds
 *   n - Number of random samples
 * Output:
 *   Returns the approximated integral value
 */
double monteCarlo(double (*f)(double), double a, double b, int n) {
    double sum = 0.0;
    
    // Iterate n times to generate random samples
    for (int i = 0; i < n; i++) {
        // Generate a random double between 0.0 and 1.0
        double r = (double)rand() / RAND_MAX;
        
        // Map the random number to the interval [a, b]
        double x = a + (b - a) * r;
        
        // Evaluate the function at the random point and add to the sum
        sum += f(x);
    }
    
    // Calculate the mean of the function evaluations
    double mean = sum / n;
    
    // Multiply the mean by the width of the interval
    return (b - a) * mean;
}

// Function to test: f(x) = x^2
double test_func(double x) {
    return x * x;
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));
    
    // Setup test parameters
    double a = 0.0;
    double b = 1.0;
    int n = 10000;
    
    // Calculate the integral
    double result = monteCarlo(test_func, a, b, n);
    
    // Display the result
    printf("Monte Carlo Integration Result: %f\n", result);
    
    return 0;
}