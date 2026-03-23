#include <stdio.h>
#include <stdlib.h>

/* Structure to hold Spline Coefficients for each interval 
   S_i(x) = a + b(x-xi) + c(x-xi)^2 + d(x-xi)^3 
*/
typedef struct {
    double *x;  // Original x points
    double *a;  // Original y points (coefficient a)
    double *b;  // Coefficient b
    double *c;  // Coefficient c
    double *d;  // Coefficient d
    int n;      // Number of points
} Spline;

/*
 * Function: buildNaturalSpline
 * ----------------------------
 * Solves the tridiagonal system to find spline coefficients.
 */
Spline buildNaturalSpline(int n, double *x, double *y) {
    Spline sp;
    sp.n = n;
    sp.x = x; // Store reference to original data
    sp.a = y; // a_i is just y_i

    // Allocate memory for coefficients and temporary calculation arrays
    sp.b = (double *)malloc(n * sizeof(double));
    sp.c = (double *)malloc(n * sizeof(double));
    sp.d = (double *)malloc(n * sizeof(double));
    double *h = (double *)malloc(n * sizeof(double));
    double *alpha = (double *)malloc(n * sizeof(double));
    double *l = (double *)malloc(n * sizeof(double));
    double *mu = (double *)malloc(n * sizeof(double));
    double *z = (double *)malloc(n * sizeof(double));

    // Step 1: Calculate step sizes h
    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

    // Step 2: Calculate alpha (RHS of the system)
    for (int i = 1; i < n - 1; i++) {
        alpha[i] = (3.0 / h[i]) * (sp.a[i + 1] - sp.a[i]) - (3.0 / h[i - 1]) * (sp.a[i] - sp.a[i - 1]);
    }

    // Step 3: Solve Tridiagonal System (Thomas Algorithm / Crout Factorization)
    // Natural Boundary Conditions: l[0] = 1, mu[0] = 0, z[0] = 0
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    // Natural Boundary Condition at end
    l[n - 1] = 1.0;
    z[n - 1] = 0.0;
    sp.c[n - 1] = 0.0;

    // Step 4: Back substitution to find b, c, d
    for (int j = n - 2; j >= 0; j--) {
        sp.c[j] = z[j] - mu[j] * sp.c[j + 1];
        sp.b[j] = (sp.a[j + 1] - sp.a[j]) / h[j] - h[j] * (sp.c[j + 1] + 2.0 * sp.c[j]) / 3.0;
        sp.d[j] = (sp.c[j + 1] - sp.c[j]) / (3.0 * h[j]);
    }

    // Free temporary arrays
    free(h); free(alpha); free(l); free(mu); free(z);

    return sp;
}

/*
 * Function: evalSpline
 * --------------------
 * equivalent to ppval(pp, val)
 */
double evalSpline(Spline sp, double val) {
    int n = sp.n;
    // Handle out of bounds (clamping)
    if (val <= sp.x[0]) return sp.a[0];
    if (val >= sp.x[n - 1]) return sp.a[n - 1];

    // Find the interval [x_i, x_{i+1}] containing val
    // Using simple linear search (Binary search is better for large n)
    int i = 0;
    for (i = 0; i < n - 1; i++) {
        if (val >= sp.x[i] && val <= sp.x[i + 1]) {
            break;
        }
    }

    // Evaluate polynomial: S(x) = a + b(dx) + c(dx)^2 + d(dx)^3
    double dx = val - sp.x[i];
    return sp.a[i] + sp.b[i] * dx + sp.c[i] * dx * dx + sp.d[i] * dx * dx * dx;
}

/* 
 * Function to free spline memory
 */
void freeSpline(Spline sp) {
    free(sp.b);
    free(sp.c);
    free(sp.d);
}

int main() {
    // Input Data
    double x_points[] = {0.0, 1.0, 2.0};
    double y_points[] = {1.0, 3.0, 2.0};
    int n = 3;

    // Build the Spline (Equivalent to pp = spline(...))
    Spline pp = buildNaturalSpline(n, x_points, y_points);

    // Test a specific value (Equivalent to y = ppval(pp, 1.5))
    double test_x = 1.5;
    double result = evalSpline(pp, test_x);

    printf("Natural Cubic Spline Result:\n");
    printf("Interpolated value at x = %.2f is %.4f\n", test_x, result);

    // Clean up
    freeSpline(pp);

    return 0;
}