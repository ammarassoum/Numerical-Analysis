#include <stdio.h>
#include <stdlib.h>

/**
 * Implements the Third-Order Taylor's Method for solving ODEs.
 * 
 * @param f     Function pointer for dy/dt
 * @param df    Function pointer for d^2y/dt^2
 * @param ddf   Function pointer for d^3y/dt^3
 * @param t0    Initial time
 * @param y0    Initial value
 * @param h     Step size
 * @param t_end Final time
 * @param t_out Array to store time steps (pre-allocated)
 * @param y_out Array to store solutions (pre-allocated)
 */
void taylor3(double (*f)(double, double), 
             double (*df)(double, double), 
             double (*ddf)(double, double),
             double t0, double y0, double h, double t_end, 
             double *t_out, double *y_out) {
    
    int n_steps = (int)((t_end - t0) / h) + 1;
    
    t_out[0] = t0;
    y_out[0] = y0;
    
    for (int i = 0; i < n_steps - 1; i++) {
        double ti = t_out[i];
        double yi = y_out[i];
        
        // Taylor series expansion: y + hf + (h^2/2)df + (h^3/6)ddf
        double term1 = h * f(ti, yi);
        double term2 = (h * h / 2.0) * df(ti, yi);
        double term3 = (h * h * h / 6.0) * ddf(ti, yi);
        
        y_out[i+1] = yi + term1 + term2 + term3;
        t_out[i+1] = ti + h;
    }
}

// --- Define functions for the test case ---

double f_test(double t, double y) {
    return -2.0 * y + t;
}

double df_test(double t, double y) {
    return -2.0; 
}

double ddf_test(double t, double y) {
    return 0.0;
}

int main() {
    double t0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double t_end = 2.0;
    
    // Calculate number of points
    int n_steps = (int)((t_end - t0) / h) + 1;
    
    // Allocate memory
    double *t = (double *)malloc(n_steps * sizeof(double));
    double *y = (double *)malloc(n_steps * sizeof(double));
    
    if (t == NULL || y == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Execute Method
    taylor3(f_test, df_test, ddf_test, t0, y0, h, t_end, t, y);
    
    // Display results
    printf("Third-Order Taylor Method Results:\n");
    printf("%-10s %-10s\n", "t", "y");
    printf("----------------------\n");
    for (int i = 0; i < n_steps; i++) {
        printf("%-10.2f %-10.5f\n", t[i], y[i]);
    }
    
    // Cleanup
    free(t);
    free(y);
    
    return 0;
}