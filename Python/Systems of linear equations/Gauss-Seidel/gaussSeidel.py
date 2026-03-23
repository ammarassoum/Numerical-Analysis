import numpy as np

def gauss_seidel(A, b, tol, max_iter):
    """
    Function to solve Ax = b using Gauss-Seidel iteration
    
    Parameters:
    A (numpy.ndarray): Coefficient matrix (n x n)
    b (numpy.ndarray): Right-hand side vector (n)
    tol (float): Convergence tolerance
    max_iter (int): Maximum number of iterations
    
    Returns:
    x (numpy.ndarray): Solution vector
    """
    
    # Ensure inputs are numpy arrays
    A = np.array(A, dtype=float)
    b = np.array(b, dtype=float).flatten() # Ensure b is a 1D vector
    
    n = len(b)
    x = np.zeros(n) # Initial guess (zeros)

    for k in range(max_iter):
        x_old = x.copy() # Store previous iteration (Must use .copy() in Python)
        
        for i in range(n):
            sigma = 0
            for j in range(n):
                if j != i:
                    # Summation of A[i, j] * x[j]
                    # Note: Python uses 0-based indexing
                    sigma += A[i, j] * x[j]
            
            # Update x[i]
            # Gauss-Seidel uses the most recent x values immediately
            x[i] = (b[i] - sigma) / A[i, i]

        # Check for convergence
        # np.linalg.norm(..., np.inf) is equivalent to norm(..., inf) in MATLAB
        if np.linalg.norm(x - x_old, np.inf) < tol:
            print(f'Gauss-Seidel converged in {k + 1} iterations.')
            return x

    print('Gauss-Seidel method did not converge within the maximum iterations.')
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

    # Call the function
    x = gauss_seidel(A, b, tol, max_iter)

    print('Solution using Gauss-Seidel Method:')
    # Reshape for column-vector style printing to match MATLAB
    print(x.reshape(-1, 1))