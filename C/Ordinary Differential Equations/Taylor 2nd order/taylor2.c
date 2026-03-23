#include <stdio.h>
#include <stdlib.h>

/**
 * Implements the Second-Order Taylor's Method for solving ODEs.
 * 
 * @param f     Function pointer for dy/dt = f(t, y)
 * @param df    Function pointer for d^2y/dt^2
 * @param t0    Initial time
 * @param y0    Initial value
 * @param h     Step size
 * @param t_end Final time
 * @param t_out Array to store time steps (must be pre-allocated)
 * @param y_out Array to store solutions (must be pre-allocated)
 */
void taylor2(double (*f)(double, double), double (*df)(double, double), 
             double t0, double y0, double h, double t_end, 
             double *t_out, double *y_out) {
    
    int n_steps = (int)((t_end - t0) / h) + 1;
    
    t_out[0] = t0;
    y_out[0] = y0;
    
    for (int i = 0; i < n_steps - 1; i++) {
        double ti = t_out[i];
        double yi = y_out[i];
        
        // Taylor series expansion: y(i+1) = y(i) + h*f + (h^2/2)*df
        y_out[i+1] = yi + h * f(ti, yi) + (h * h / 2.0) * df(ti, yi);
        t_out[i+1] = ti + h;
    }
}

// Example ODE: dy/dt = -2y + t
double f_example(double t, double y) {
    return -2.0 * y + t;
}

// Example 2nd derivative: d^2y/dt^2
double df_example(double t, double y) {
    return -2.0; 
}

int main() {
    double t0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double t_end = 2.0;
    
    // Calculate number of steps
    int n_steps = (int)((t_end - t0) / h) + 1;
    
    // Allocate memory for results
    double *t = (double *)malloc(n_steps * sizeof(double));
    double *y = (double *)malloc(n_steps * sizeof(double));
    
    // Execute Taylor Method
    taylor2(f_example, df_example, t0, y0, h, t_end, t, y);
    
    // Print Results
    printf("t\t\ty\n");
    printf("--------------------------\n");
    for (int i = 0; i < n_steps; i++) {
        printf("%.2f\t\t%.5f\n", t[i], y[i]);
    }
    
    // Free allocated memory
    free(t);
    free(y);
    
    return 0;
}