def central_difference(f, x, h):
    """
    Implements Second-Order Central Difference for the first derivative.
    
    Inputs:
        f - Function handle (callable)
        x - Point at which to compute the derivative
        h - Step size
        
    Output:
        df - Approximated derivative at x
    """
    # Formula: (f(x + h) - f(x - h)) / (2 * h)
    df = (f(x + h) - f(x - h)) / (2 * h)
    return df

# --- Test the function ---
if __name__ == "__main__":
    # Define the function: f(x) = x^2
    f = lambda x: x**2
    
    # Define point and step size
    x = 2
    h = 0.01
    
    # Calculate derivative
    df = central_difference(f, x, h)
    
    # Print result
    print(f"Central Difference Result: {df:.5f}")
    # Exact derivative of x^2 at x=2 is 4.0. 
    # For a quadratic function, central difference is often very precise.