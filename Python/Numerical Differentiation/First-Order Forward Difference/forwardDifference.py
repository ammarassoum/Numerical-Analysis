def forward_difference(f, x, h):
    """
    Implements First-Order Forward Difference.
    
    Inputs:
        f - Function handle (callable)
        x - Point at which to compute the derivative
        h - Step size
        
    Output:
        df - Approximated derivative at x
    """
    # Formula: (f(x + h) - f(x)) / h
    df = (f(x + h) - f(x)) / h
    return df

# --- Test the function ---
if __name__ == "__main__":
    # Define the function: f(x) = x^2
    f = lambda x: x**2
    
    # Define point and step size
    x = 2
    h = 0.01
    
    # Calculate derivative
    df = forward_difference(f, x, h)
    
    # Print result formatted to 5 decimal places
    print(f"Forward Difference Result: {df:.5f}")
    # Exact derivative of x^2 at x=2 is 4.0. 
    # Forward difference result will be 4.01.