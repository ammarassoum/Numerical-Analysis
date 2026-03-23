def romberg(f, a, b, m):
    """
    Implements Romberg Integration for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      m - Maximum number of levels
    Output:
      Approximated integral value
    """
    # Initialize an m x m matrix with zeros
    R = [[0.0] * m for _ in range(m)]
    
    h = float(b - a)
    
    # First estimate (Trapezoidal rule with 1 interval)
    R[0][0] = (h / 2.0) * (f(a) + f(b))
    
    for k in range(1, m):
        h /= 2.0
        
        # Sum evaluations at new interior points (odd multiples of the new h)
        # We need exactly 2**(k-1) new points
        summation = sum(f(a + h + i * 2.0 * h) for i in range(2**(k-1)))
        
        # Recursive Trapezoidal rule
        R[k][0] = 0.5 * R[k-1][0] + h * summation
        
        # Richardson extrapolation to complete the row
        for j in range(1, k + 1):
            R[k][j] = R[k][j-1] + (R[k][j-1] - R[k-1][j-1]) / (4**j - 1.0)
            
    # The final result is the bottom-most, right-most element
    return R[m-1][m-1]

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    m = 4
    
    # Calculate the integral
    result = romberg(f, a, b, m)
    
    # Display the result (Expected: ~0.3333333333333333)
    print(f"Romberg Integration Result: {result}")