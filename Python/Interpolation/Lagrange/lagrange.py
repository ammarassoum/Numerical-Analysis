import numpy as np

def lagrange(x, y_points, x_points):
    """
    Function for Lagrange Interpolation
    
    Parameters:
    x (float or numpy.ndarray): Point(s) to interpolate
    y_points (numpy.ndarray): Function values at x_points
    x_points (numpy.ndarray): Known data points
    
    Returns:
    y (float or numpy.ndarray): Interpolated value(s) at x
    """
    
    # Ensure inputs are numpy arrays for element-wise operations
    x_points = np.array(x_points, dtype=float)
    y_points = np.array(y_points, dtype=float)
    
    # Handle x as an array (even if scalar input, allows consistent math)
    # However, if x is a simple float, numpy handles the broadcasting automatically.
    
    n = len(x_points)
    
    # Initialize y with zeros, same shape as x
    # If x is scalar, y is scalar 0.0. If x is array, y is array of zeros.
    y = np.zeros_like(x, dtype=float)
    
    # Outer loop: Iterate over each known data point
    for i in range(n):
        # Initialize the Lagrange basis polynomial L_i(x)
        # We start with 1 because we will be multiplying
        L = np.ones_like(x, dtype=float)
        
        # Inner loop: Build the basis polynomial
        for j in range(n):
            if i != j:
                # L *= (x - x_j) / (x_i - x_j)
                L = L * (x - x_points[j]) / (x_points[i] - x_points[j])
        
        # Add the weighted basis polynomial to the result
        y = y + L * y_points[i]
        
    return y

# --- Test Driver ---
if __name__ == "__main__":
    # Test Data from MATLAB example
    x_points = [0, 1, 2]
    y_points = [1, 3, 2]
    x = 1.5
    
    # Call the function
    # Note: We pass y_points before x_points to match the specific 
    # signature requested in the MATLAB code prompt.
    result = lagrange(x, y_points, x_points)
    
    print(f"Lagrange interpolation at x = {x}: {result}")