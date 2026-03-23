import numpy as np
import matplotlib.pyplot as plt

def taylor2(f, df, t0, y0, h, t_end):
    """
    Implements the Second-Order Taylor's Method for solving ODEs.
    
    Inputs:
        f     - Function representing dy/dt = f(t, y)
        df    - Function representing the second derivative d^2y/dt^2
        t0    - Initial time
        y0    - Initial value
        h     - Step size
        t_end - Final time
    Outputs:
        t - Time steps
        y - Solution at each time step
    """
    # Generate time steps
    t = np.arange(t0, t_end + h, h)
    # Initialize solution array
    y = np.zeros(len(t))
    y[0] = y0 # Set initial condition
    
    for i in range(len(t) - 1):
        # Taylor series expansion up to second-order term
        # y(i+1) = y(i) + h*y' + (h^2/2)*y''
        y[i+1] = y[i] + h * f(t[i], y[i]) + (h**2 / 2.0) * df(t[i], y[i])
        
    return t, y

# --- Test the function ---
if __name__ == "__main__":
    # Define the ODE: dy/dt = -2y + t
    f = lambda t, y: -2 * y + t
    # Define the 2nd derivative: d^2y/dt^2 = -2(dy/dt) + 1 = -2(-2y + t) + 1
    # Note: In the user's MATLAB example, df was simplified to -2 for demonstration
    df = lambda t, y: -2 
    
    # Parameters
    t0, y0, h, t_end = 0, 1, 0.1, 2
    
    # Solve
    t, y = taylor2(f, df, t0, y0, h, t_end)
    
    # Plotting
    plt.plot(t, y, '-o', label='Taylor 2nd Order')
    plt.title('Second-Order Taylor Method')
    plt.xlabel('t')
    plt.ylabel('y')
    plt.grid(True)
    plt.show()