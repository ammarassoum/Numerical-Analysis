import matplotlib.pyplot as plt

def rk4(f, t0, y0, h, t_end):
    """
    Implements the Fourth-Order Runge-Kutta Method for solving ODEs
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
    
    # RK4 method loop
    for i in range(num_steps - 1):
        k1 = h * f(t[i], y[i])                           # Slope at the beginning
        k2 = h * f(t[i] + h / 2.0, y[i] + k1 / 2.0)      # Slope at midpoint using k1
        k3 = h * f(t[i] + h / 2.0, y[i] + k2 / 2.0)      # Slope at midpoint using k2
        k4 = h * f(t[i] + h, y[i] + k3)                  # Slope at the end
        
        y[i + 1] = y[i] + (k1 + 2*k2 + 2*k3 + k4) / 6.0  # Weighted average
        
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
    t_vals, y_vals = rk4(f, t0, y0, h, t_end)
    
    # Plot the results replicating MATLAB's behavior
    plt.plot(t_vals, y_vals, '-o', label="RK4 Approximation")
    plt.title("Runge-Kutta 4th Order Method")
    plt.xlabel('t')
    plt.ylabel('y')
    plt.grid(True)
    plt.legend()
    plt.show()