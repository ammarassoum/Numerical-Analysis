import numpy as np

def chebyshev(func, n, a, b):
    """
    Function for Chebyshev Interpolation
    
    Parameters:
    func (callable): Function to interpolate (e.g., lambda x: ...)
    n (int): Number of Chebyshev points
    a (float): Start of interval
    b (float): End of interval
    
    Returns:
    x_cheb (numpy.ndarray): Chebyshev nodes mapped to [a, b]
    y_cheb (numpy.ndarray): Function values at Chebyshev nodes
    """
    
    # Generate index array k = 1, 2, ..., n
    k = np.arange(1, n + 1)
    
    # Calculate Chebyshev nodes on [-1, 1] and map them to [a, b]
    # Formula: 0.5 * ((b - a) * cos((2k - 1) * pi / (2n)) + (b + a))
    x_cheb = 0.5 * ((b - a) * np.cos((2 * k - 1) * np.pi / (2 * n)) + (b + a))
    
    # Evaluate the function at these nodes
    y_cheb = func(x_cheb)
    
    return x_cheb, y_cheb

# --- Test Driver ---
if __name__ == "__main__":
    # Define Runge's function: f(x) = 1 / (1 + x^2)
    func = lambda x: 1.0 / (1.0 + x**2)
    
    a = -5
    b = 5
    n = 10
    
    # Call the function
    x_nodes, y_values = chebyshev(func, n, a, b)
    
    print("Chebyshev nodes and function values:")
    print(f"{'x':>12} | {'y':>12}")
    print("-" * 27)
    
    # Print results in two columns
    for x_val, y_val in zip(x_nodes, y_values):
        print(f"{x_val:12.6f} | {y_val:12.6f}")