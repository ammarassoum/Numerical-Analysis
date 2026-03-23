#include <stdio.h>
#include <stdlib.h>

/*
 * Function: linearSpline
 * ----------------------
 * Performs linear interpolation for an array of query points.
 *
 * Inputs:
 *   n_data   - Number of known data points
 *   x_points - Array of known x coordinates (must be sorted)
 *   y_points - Array of known y coordinates
 *   n_query  - Number of points to interpolate
 *   x        - Array of points to interpolate
 *   y        - Output array to store results
 */
void linearSpline(int n_data, double *x_points, double *y_points, 
                  int n_query, double *x, double *y) {
    
    // Initialize output array to 0 (optional, but good practice)
    for (int k = 0; k < n_query; k++) {
        y[k] = 0.0;
    }

    // Iterate over each point we want to interpolate (x[k])
    for (int k = 0; k < n_query; k++) {
        double val = x[k];
        
        // Find which segment [x_points[i], x_points[i+1]] contains 'val'
        for (int i = 0; i < n_data - 1; i++) {
            if (val >= x_points[i] && val <= x_points[i+1]) {
                
                // Calculate slope: (y2 - y1) / (x2 - x1)
                double slope = (y_points[i+1] - y_points[i]) / 
                               (x_points[i+1] - x_points[i]);
                
                // Apply linear equation: y = y1 + slope * (x - x1)
                y[k] = y_points[i] + slope * (val - x_points[i]);
                
                // Once found, we can break the inner loop for this point
                break; 
            }
        }
    }
}

int main() {
    // --- Test Data ---
    // x_points = [0, 1, 2]
    double x_points[] = {0.0, 1.0, 2.0};
    
    // y_points = [1, 3, 2]
    double y_points[] = {1.0, 3.0, 2.0};
    
    // Point to interpolate (as an array)
    double x_query[] = {1.5};
    double y_result[1]; // Array to hold result
    
    // Calculate sizes
    int n_data = sizeof(x_points) / sizeof(x_points[0]);
    int n_query = sizeof(x_query) / sizeof(x_query[0]);

    // Call the function
    linearSpline(n_data, x_points, y_points, n_query, x_query, y_result);

    // Display Result
    printf("Linear spline interpolation at x = %.1f: %.4f\n", x_query[0], y_result[0]);

    return 0;
}