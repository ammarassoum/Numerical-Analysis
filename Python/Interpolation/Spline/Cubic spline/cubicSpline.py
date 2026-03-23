import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

def cubic_spline(x_points, y_points):
    """
    Function for Cubic Spline Interpolation
    
    Parameters:
    x_points (array-like): Known x data points
    y_points (array-like): Known y data points
    
    Returns:
    pp: A CubicSpline object (equivalent to MATLAB's pp structure)
        This object can be called like a function: y = pp(x)
    """
    
    # Create the spline object. 
    # bc_type='not-a-knot' is the default and matches MATLAB's 'spline' behavior.
    pp = CubicSpline(x_points, y_points, bc_type='not-a-knot')
    
    return pp

# --- Test Driver ---
if __name__ == "__main__":
    # Test Data
    x_points = np.array([0, 1, 2])
    y_points = np.array([1, 3, 2])
    
    # Create the spline structure
    pp = cubic_spline(x_points, y_points)
    
    # Generate dense grid for plotting (equivalent to linspace)
    x_dense = np.linspace(0, 2, 100)
    
    # Evaluate the spline at x_dense (equivalent to ppval)
    y_dense = pp(x_dense)
    
    # Display a specific value to verify calculation
    val_at_1_5 = pp(1.5)
    print(f"Interpolated value at x = 1.5: {val_at_1_5:.4f}")

    # Plotting (requires matplotlib)
    try:
        plt.figure()
        plt.plot(x_points, y_points, 'o', label='Data Points')
        plt.plot(x_dense, y_dense, '-', label='Cubic Spline')
        plt.title('Cubic Spline Interpolation')
        plt.legend()
        plt.grid(True)
        plt.show()
    except Exception as e:
        print("Matplotlib not available or failed to plot.")