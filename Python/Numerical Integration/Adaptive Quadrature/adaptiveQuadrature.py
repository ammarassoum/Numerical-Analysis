def adaptive_quadrature(f, a, b, tol):
    """
    Implements Adaptive Quadrature for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      tol - Error tolerance
    Output:
      Approximated integral value
    """
    c = (a + b) / 2.0
    
    # Single Simpson's rule over the whole interval
    approx1 = (b - a) * (f(a) + 4 * f(c) + f(b)) / 6.0
    
    # Split interval: Simpson's rule on [a,c] and [c,b]
    approx2 = ((c - a) * (f(a) + 4 * f((a + c) / 2.0) + f(c)) + \
               (b - c) * (f(c) + 4 * f((c + b) / 2.0) + f(b))) / 6.0
    
    # Check if the difference is within the acceptable tolerance
    if abs(approx2 - approx1) < 15 * tol:
        return approx2
    else:
        # Recursive call for both halves, with halved tolerance
        return adaptive_quadrature(f, a, c, tol / 2.0) + adaptive_quadrature(f, c, b, tol / 2.0)

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    tol = 1e-5
    
    # Calculate the integral
    result = adaptive_quadrature(f, a, b, tol)
    
    # Display the result
    print(f"Adaptive Quadrature Result: {result}")