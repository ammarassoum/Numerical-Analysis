def midpoint(f, a, b, n):
    """
    Implements the Midpoint Rule for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      n - Number of subintervals
    Output:
      Approximated integral value
    """
    h = (b - a) / n  # Width of each subinterval
    
    # Generate midpoints, evaluate the function, and sum the results.
    # We use a generator expression for memory efficiency.
    total_sum = sum(f(a + h/2.0 + i * h) for i in range(n))
    
    # Multiply the sum by the interval width
    result = h * total_sum
    
    return result

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    n = 10
    
    # Calculate the integral
    result = midpoint(f, a, b, n)
    
    # Display the result
    print(f"Midpoint Rule Result: {result}")