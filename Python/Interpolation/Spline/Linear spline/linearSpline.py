import numpy as np

def linear_spline(x, x_points, y_points):
    """
    Function for Linear Spline Interpolation
    
    Parameters:
    x (float or np.ndarray): Point(s) to interpolate
    x_points (np.ndarray): Known x data points (must be sorted ascending)
    y_points (np.ndarray): Known y data points
    
    Returns:
    y (np.ndarray): Interpolated value(s) at x
    """
    
    # Ensure inputs are numpy arrays
    x_points = np.array(x_points, dtype=float)
    y_points = np.array(y_points, dtype=float)
    
    # Handle scalar input for x by converting to at least 1D array, 
    # then we can treat it consistently.
    x = np.atleast_1d(x)
    
    n = len(x_points) - 1
    y = np.zeros_like(x, dtype=float)
    
    # Loop through each segment [x_i, x_{i+1}]
    # This logic exactly mirrors the MATLAB approach
    for i in range(n):
        # Find indices in x that fall within the current segment
        # logical_and creates a boolean mask
        idx = np.logical_and(x >= x_points[i], x <= x_points[i+1])
        
        # Apply the linear equation for this segment
        # y = y_i + slope * (x - x_i)
        slope = (y_points[i+1] - y_points[i]) / (x_points[i+1] - x_points[i])
        y[idx] = y_points[i] + slope * (x[idx] - x_points[i])
        
    return y

# --- Test Driver ---
if __name__ == "__main__":
    # Define known data points
    x_points = [0, 1, 2]
    y_points = [1, 3, 2]
    
    # Define point to interpolate
    val_to_interpolate = 1.5
    
    # Call the function
    result = linear_spline(val_to_interpolate, x_points, y_points)
    
    # Print the result (accessing index 0 since result is an array)
    print(f"Linear spline interpolation at x = {val_to_interpolate}: {result[0]}")