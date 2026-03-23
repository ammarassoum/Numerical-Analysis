#include <stdio.h>
#include <stdlib.h>

/* 
 * Implements the Second-Order Runge-Kutta Method for solving ODEs
 * Inputs:
 *   f - Function pointer representing dy/dt = f(t, y)
 *   t0 - Initial time
 *   y0 - Initial value
 *   h - Step size
 *   t_end - Final time
 * Outputs (via pointers):
 *   t_out - Pointer to the time steps array
 *   y_out - Pointer to the solution array
 *   n_out - Pointer to the number of steps (array size)
 */
void rk2(double (*f)(double, double), double t0, double y0, double h, double t_end, 
         double **t_out, double **y_out, int *n_out) {
    
    // Calculate the total number of points (adding 0.5 prevents floating point truncation)
    int n = (int)((t_end - t0) / h + 0.5) + 1;
    *n_out = n;
    
    // Allocate memory for time and solution arrays
    double *t = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));
    
    // Initialize the first values
    t[0] = t0;
    y[0] = y0;
    
    // Pre-calculate all time steps
    for (int i = 1; i < n; i++) {
        t[i] = t0 + i * h;
    }
    
    // RK2 method loop
    for (int i = 0; i < n - 1; i++) {
        double k1 = h * f(t[i], y[i]);                 // Slope at the beginning of the interval
        double k2 = h * f(t[i] + h, y[i] + k1);        // Slope at the end of the interval
        y[i + 1] = y[i] + 0.5 * (k1 + k2);             // Weighted average slope
    }
    
    // Point the output arguments to our newly created arrays
    *t_out = t;
    *y_out = y;
}

// Function to test: dy/dt = -2y + t
double test_func(double t, double y) {
    return -2.0 * y + t;
}

int main() {
    // Setup test parameters
    double t0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double t_end = 2.0;
    
    // Pointers to hold our output arrays and variable for array size
    double *t = NULL;
    double *y = NULL;
    int num_steps = 0;
    
    // Call RK2 method
    rk2(test_func, t0, y0, h, t_end, &t, &y, &num_steps);
    
    // Print the result as a formatted table
    printf("Runge-Kutta 2nd Order Results:\n");
    printf("%-10s %-10s\n", "t", "y");
    printf("---------------------\n");
    for(int i = 0; i < num_steps; i++) {
        printf("%-10.4f %-10.4f\n", t[i], y[i]);
    }
    
    // Free the dynamically allocated memory
    free(t);
    free(y);
    
    return 0;
}