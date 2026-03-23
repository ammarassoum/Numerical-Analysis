def simpson(f, a, b, n):
    """
    Implements Simpson's Rule for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      n - Number of subintervals (must be even)
    Output:
      Approximated integral value
    """
    if n % 2 != 0:
        raise ValueError("n must be an even number for Simpson's rule.")
        
    h = (b - a) / n  # Width of each subinterval
    
    # Sum the odd-indexed terms: x_1, x_3, ..., x_{n-1}
    # range(1, n, 2) starts at 1, stops before n, steps by 2
    sum_odd = sum(f(a + i * h) for i in range(1, n, 2))
    
    # Sum the even-indexed terms: x_2, x_4, ..., x_{n-2}
    # range(2, n, 2) starts at 2, stops before n, steps by 2
    sum_even = sum(f(a + i * h) for i in range(2, n, 2))
    
    # Apply Simpson's 1/3 rule formula: (h/3) * [f(x_0) + 4*sum_odd + 2*sum_even + f(x_n)]
    result = (h / 3.0) * (f(a) + 4 * sum_odd + 2 * sum_even + f(b))
    
    return result

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    n = 10
    
    # Calculate the integral
    result = simpson(f, a, b, n)
    
    # Display the result (Expected: ~0.3333333333333333)
    print(f"Simpson's Rule Result: {result}")