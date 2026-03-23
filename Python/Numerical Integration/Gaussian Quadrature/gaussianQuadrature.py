import math

def lgwt(n, a, b):
    """
    Generate nodes and weights for Gaussian quadrature
    Adapted from Numerical Recipes
    """
    # Initial guess for the roots
    x = [math.cos(math.pi * (4 * (i + 1) - 1) / (4 * n + 2)) for i in range(n)]
    w = [0.0] * n
    
    max_iter = 100
    tol = 1e-14
    
    for k in range(max_iter):
        x_new = [0.0] * n
        dp = [0.0] * n
        max_diff = 0.0
        
        for i in range(n):
            p0 = 0.0
            p1 = 1.0
            p2 = 0.0
            
            # Evaluate Legendre polynomial
            for j in range(1, n + 1):
                p2 = p0
                p0 = p1
                p1 = ((2 * j - 1) * x[i] * p0 - (j - 1) * p2) / j
            
            # Derivative of the Legendre polynomial
            dp[i] = n * (p0 - x[i] * p1) / (1.0 - x[i]**2)
            
            # Newton step
            x_new[i] = x[i] - p1 / dp[i]
            
            # Track max difference
            diff = abs(x_new[i] - x[i])
            if diff > max_diff:
                max_diff = diff
                
        # Break if tolerance is achieved
        if max_diff < tol:
            for i in range(n):
                w[i] = 2.0 / ((1.0 - x[i]**2) * dp[i]**2)
            break
        
        # Update x for next iteration
        for i in range(n):
            x[i] = x_new[i]
            
    else:
        # If max_iter reached without breaking, calculate weights anyway
        for i in range(n):
            w[i] = 2.0 / ((1.0 - x[i]**2) * dp[i]**2)
            
    # Map from standard interval [-1, 1] to target interval [a, b]
    for i in range(n):
        x[i] = (a + b) / 2.0 + (b - a) / 2.0 * x[i]
        w[i] = (b - a) / 2.0 * w[i]
        
    return x, w

def gaussian_quadrature(f, a, b, n):
    """
    Implements Gaussian Quadrature for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      n - Number of quadrature points
    Output:
      Approximated integral value
    """
    # Get nodes and weights for Gaussian quadrature
    nodes, weights = lgwt(n, a, b)
    
    # Calculate the sum: w_i * f(x_i)
    result = sum(w * f(node) for node, w in zip(nodes, weights))
    
    return result

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    n = 3
    
    # Calculate the integral
    result = gaussian_quadrature(f, a, b, n)
    
    # Display the result
    print(f"Gaussian Quadrature Result: {result}")