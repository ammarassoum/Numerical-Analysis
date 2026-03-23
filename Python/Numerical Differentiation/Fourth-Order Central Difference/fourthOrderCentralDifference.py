def fourth_order_central_difference(f, x, h):
    """
    Implements Fourth-Order Central Difference for the first derivative.
    
    Inputs:
        f - Function handle (callable)
        x - Point at which to compute the derivative
        h - Step size
        
    Output:
        df - Approximated derivative at x
    """
    # Formula: [-f(x+2h) + 8f(x+h) - 8f(x-h) + f(x-2h)] / (12h)
    numerator = -f(x + 2*h) + 8*f(x + h) - 8*f(x - h) + f(x - 2*h)
    denominator = 12 * h
    
    df = numerator / denominator
    return df

# --- Test the function ---
if __name__ == "__main__":
    # Define the function: f(x) = x^2
    f = lambda x: x**2
    
    # Define point and step size
    x = 2
    h = 0.01
    
    # Calculate derivative
    df = fourth_order_central_difference(f, x, h)
    
    # Print result
    print(f"Fourth-Order Central Difference Result: {df:.10f}")
    # For f(x)=x^2, the result should be exactly 4.0 (within machine precision)