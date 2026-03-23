def backward_difference(f, x, h):
    """
    Implements First-Order Backward Difference.
    
    Inputs:
        f - Function handle (callable)
        x - Point at which to compute the derivative
        h - Step size
        
    Output:
        df - Approximated derivative at x
    """
    # Formula: (f(x) - f(x - h)) / h
    df = (f(x) - f(x - h)) / h
    return df

# --- Test the function ---
if __name__ == "__main__":
    # Define the function: f(x) = x^2
    f = lambda x: x**2
    
    # Define point and step size
    x = 2
    h = 0.01
    
    # Calculate derivative
    df = backward_difference(f, x, h)
    
    # Print result
    print(f"Backward Difference Result: {df:.5f}")
    # Exact derivative of x^2 at x=2 is 4.0