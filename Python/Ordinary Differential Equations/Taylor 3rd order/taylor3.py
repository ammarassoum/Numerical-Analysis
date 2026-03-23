import numpy as np
import matplotlib.pyplot as plt

def taylor3(f, df, ddf, t0, y0, h, t_end):
    """
    Implements the Third-Order Taylor's Method for solving ODEs.
    
    Inputs:
        f     - Function representing dy/dt = f(t, y)
        df    - Function representing the second derivative d^2y/dt^2
        ddf   - Function representing the third derivative d^3y/dt^3
        t0    - Initial time
        y0    - Initial value
        h     - Step size
        t_end - Final time
    Outputs:
        t - Time steps
        y - Solution at each time step
    """
    # Generate time steps (t_end + h to ensure t_end is included)
    t = np.arange(t0, t_end + h, h)
    # Initialize solution array
    y = np.zeros(len(t))
    y[0] = y0  # Set initial condition
    
    for i in range(len(t) - 1):
        # Taylor series expansion up to third-order term:
        # y(i+1) = y(i) + h*y' + (h^2/2)*y'' + (h^3/6)*y'''
        term1 = h * f(t[i], y[i])
        term2 = (h**2 / 2.0) * df(t[i], y[i])
        term3 = (h**3 / 6.0) * ddf(t[i], y[i])
        
        y[i+1] = y[i] + term1 + term2 + term3
        
    return t, y

# --- Test the function ---
if __name__ == "__main__":
    # Define the ODE and its derivatives
    f = lambda t, y: -2 * y + t      # dy/dt
    df = lambda t, y: -2             # d^2y/dt^2
    ddf = lambda t, y: 0             # d^3y/dt^3
    
    # Parameters
    t0, y0, h, t_end = 0, 1, 0.1, 2
    
    # Solve
    t, y = taylor3(f, df, ddf, t0, y0, h, t_end)
    
    # Plotting results
    plt.plot(t, y, '-o', label='Taylor 3rd Order')
    plt.title('Third-Order Taylor Method')
    plt.xlabel('t')
    plt.ylabel('y')
    plt.grid(True)
    plt.legend()
    plt.show()