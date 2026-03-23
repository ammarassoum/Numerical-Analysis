import matplotlib.pyplot as plt

def rk2(f, t0, y0, h, t_end):
    """
    Implements the Second-Order Runge-Kutta Method for solving ODEs
    Inputs:
      f - Function (callable) representing dy/dt = f(t, y)
      t0 - Initial time
      y0 - Initial value
      h - Step size
      t_end - Final time
    Outputs:
      t - Time steps (list)
      y - Solution at each time step (list)
    """
    # Calculate the number of steps
    num_steps = int(round((t_end - t0) / h)) + 1
    
    # Generate time steps list
    t = [t0 + i * h for i in range(num_steps)]
    
    # Initialize solution array with zeros
    y = [0.0] * num_steps
    
    # Set initial condition
    y[0] = y0
    
    # RK2 method loop
    for i in range(num_steps - 1):
        k1 = h * f(t[i], y[i])                 # Slope at the beginning of the interval
        k2 = h * f(t[i] + h, y[i] + k1)        # Slope at the end of the interval
        y[i + 1] = y[i] + 0.5 * (k1 + k2)      # Weighted average slope
        
    return t, y

# To test the written function, run the script directly.
if __name__ == "__main__":
    # f(t, y) = -2*y + t using a lambda function
    f = lambda t, y: -2 * y + t
    
    t0 = 0.0
    y0 = 1.0
    h = 0.1
    t_end = 2.0
    
    # Solve the ODE
    t_vals, y_vals = rk2(f, t0, y0, h, t_end)
    
    # Plot the results replicating MATLAB's behavior
    plt.plot(t_vals, y_vals, '-o', label="RK2 Approximation")
    plt.title("Runge-Kutta 2nd Order Method")
    plt.xlabel('t')
    plt.ylabel('y')
    plt.grid(True)
    plt.legend()
    plt.show()