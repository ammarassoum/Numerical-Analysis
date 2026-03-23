def trapezoidal(f, a, b, n):
    """
    Implements the Trapezoidal Rule for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      n - Number of subintervals
    Output:
      Approximated integral value
    """
    h = (b - a) / n  # Width of each subinterval
    
    # Sum the interior points: x_1, x_2, ..., x_{n-1}
    # range(1, n) starts at 1 and stops at n-1
    interior_sum = sum(f(a + i * h) for i in range(1, n))
    
    # Calculate the final result applying the trapezoidal formula
    result = h * (0.5 * f(a) + interior_sum + 0.5 * f(b))
    
    return result

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    n = 10
    
    # Calculate the integral
    result = trapezoidal(f, a, b, n)
    
    # Display the result (Expected: 0.335)
    print(f"Trapezoidal Rule Result: {result}")