import numpy as np

def newton_interpolation(x, y_points, x_points):
    """
    Function for Newton Interpolation
    
    Parameters:
    x (float): Point to interpolate
    y_points (array-like): Function values at x_points
    x_points (array-like): Known data points
    
    Returns:
    y (float): Interpolated value at x
    """
    
    # Convert inputs to numpy arrays of float type
    x_points = np.array(x_points, dtype=float)
    y_points = np.array(y_points, dtype=float)
    n = len(x_points)
    
    # Initialize the divided difference table with zeros
    diff_table = np.zeros((n, n))
    
    # Fill the first column with y values
    # Note: Python uses 0-based indexing
    diff_table[:, 0] = y_points
    
    # Construct divided difference table
    # j is the column index (1 to n-1)
    for j in range(1, n):
        # i is the row index
        for i in range(n - j):
            # Formula: (Next_Row_Prev_Col - Curr_Row_Prev_Col) / (x[i+j] - x[i])
            numerator = diff_table[i + 1, j - 1] - diff_table[i, j - 1]
            denominator = x_points[i + j] - x_points[i]
            diff_table[i, j] = numerator / denominator

    # Perform interpolation
    # The coefficients are the first row of the table: diff_table[0, :]
    y = diff_table[0, 0]
    product_term = 1.0
    
    for i in range(1, n):
        # Update product term: (x - x_0) * (x - x_1) * ...
        product_term = product_term * (x - x_points[i - 1])
        
        # Add the next term to the result
        y = y + product_term * diff_table[0, i]
        
    return y

# --- Test Driver ---
if __name__ == "__main__":
    # Define data points
    x_points = [0, 1, 2]
    y_points = [1, 3, 2]
    
    # Point to interpolate
    x = 1.5
    
    # Call the function
    y = newton_interpolation(x, y_points, x_points)
    
    print(f"Newton interpolation at x = {x}: {y}")