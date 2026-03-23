def richardson_extrapolation(f, x, h):
    """
    Implements Richardson Extrapolation for Derivative Approximation.
    
    Inputs:
        f - Function handle (callable)
        x - Point at which to compute the derivative
        h - Initial step size
        
    Output:
        df - Refined approximated derivative at x
    """
    # D1: Central difference with step size h
    # Formula: [f(x + h) - f(x - h)] / (2h)
    d1 = (f(x + h) - f(x - h)) / (2 * h)
    
    # D2: Central difference with step size h/2
    # Formula: [f(x + h/2) - f(x - h/2)] / (2 * (h/2)) = [f(x + h/2) - f(x - h/2)] / h
    d2 = (f(x + h / 2.0) - f(x - h / 2.0)) / h
    
    # Richardson Extrapolation formula to combine results
    df = (4 * d2 - d1) / 3.0
    
    return df

# --- Test the function ---
if __name__ == "__main__":
    # Define the function: f(x) = x^2
    f = lambda x: x**2
    
    # Define point and step size
    x_val = 2
    h_val = 0.01
    
    # Calculate derivative
    result = richardson_extrapolation(f, x_val, h_val)
    
    # Print result
    print(f"Richardson Extrapolation Result: {result:.10f}")