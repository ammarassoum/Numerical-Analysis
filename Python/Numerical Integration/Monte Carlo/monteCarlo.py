import random

def monte_carlo(f, a, b, n):
    """
    Implements Monte Carlo Integration for numerical integration
    Inputs:
      f - Function (callable)
      a, b - Integration bounds
      n - Number of random samples
    Output:
      Approximated integral value
    """
    
    # Generate n random samples in [a, b], evaluate the function, and sum them
    # We use a generator expression for memory efficiency
    total_sum = sum(f(random.uniform(a, b)) for _ in range(n))
    
    # Calculate the mean of the evaluations
    mean_val = total_sum / n
    
    # Multiply the mean by the interval width
    result = (b - a) * mean_val
    
    return result

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(x) = x^2 using a lambda function
    f = lambda x: x**2
    a = 0.0
    b = 1.0
    n = 10000
    
    # Calculate the integral
    result = monte_carlo(f, a, b, n)
    
    # Display the result (Will vary slightly around 0.3333 on each run)
    print(f"Monte Carlo Integration Result: {result}")