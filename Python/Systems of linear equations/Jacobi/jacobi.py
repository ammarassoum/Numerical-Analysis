import numpy as np

def jacobi(A, b, tol, max_iter):
    """
    Function to solve Ax = b using Jacobi iteration
    
    Parameters:
    A (numpy.ndarray): Coefficient matrix (n x n)
    b (numpy.ndarray): Right-hand side vector (n)
    tol (float): Convergence tolerance
    max_iter (int): Maximum number of iterations
    
    Returns:
    x (numpy.ndarray): Solution vector
    """
    
    # Ensure inputs are numpy arrays of type float
    A = np.array(A, dtype=float)
    b = np.array(b, dtype=float)
    
    n = len(b)
    x = np.zeros(n)      # Initial guess (zeros)
    x_old = np.zeros(n)  # Store previous iteration values

    for k in range(max_iter):
        # Calculate new x values
        for i in range(n):
            sigma = 0
            for j in range(n):
                if j != i:
                    # Summation using x_old (values from previous step)
                    sigma += A[i, j] * x_old[j]
            
            # Compute new value for x[i]
            x[i] = (b[i] - sigma) / A[i, i]
            
        # Check for convergence
        # np.linalg.norm(vec, np.inf) matches MATLAB's norm(vec, inf)
        if np.linalg.norm(x - x_old, np.inf) < tol:
            print(f"Jacobi converged in {k + 1} iterations.")
            return x
        
        # Update x_old for the next iteration
        # IMPORTANT: Use .copy() to create a new array, 
        # otherwise x_old points to the same memory as x.
        x_old = x.copy()

    print("Warning: Jacobi method did not converge within the maximum iterations.")
    return x

# --- Test Driver ---
if __name__ == "__main__":
    # Define A, b, tol, maxIter as per the MATLAB example
    A = [[4, -1, 0], 
         [-1, 4, -1], 
         [0, -1, 4]]
    
    b = [15, 10, 10]
    
    tol = 1e-5
    max_iter = 100

    # Run the function
    solution = jacobi(A, b, tol, max_iter)

    print("Solution using Jacobi Method:")
    # Reshape for column-vector style printing (optional, matches MATLAB output style)
    print(solution.reshape(-1, 1))