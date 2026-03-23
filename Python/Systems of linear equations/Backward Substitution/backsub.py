import numpy as np

def backward_substitution(U, b):
    """
    Solves Ux = b using Backward Substitution.
    
    Parameters:
    U (numpy.ndarray): Upper triangular matrix (n x n)
    b (numpy.ndarray): Right-hand side vector (n)
    
    Returns:
    x (numpy.ndarray): Solution vector
    """
    
    # Ensure inputs are float for division
    U = np.array(U, dtype=float)
    b = np.array(b, dtype=float)
    
    n = len(b)
    x = np.zeros(n) # Initialize solution vector
    
    # Iterate from the last row (n-1) down to 0
    # range(start, stop, step) -> stop is exclusive
    for i in range(n - 1, -1, -1):
        sum_val = 0.0
        
        # Iterate over columns to the right of the diagonal
        for j in range(i + 1, n):
            sum_val += U[i, j] * x[j]
            
        # Check for singularity
        if U[i, i] == 0:
            raise ValueError(f"Matrix is singular (zero on diagonal at index {i}).")
            
        # Compute x[i]
        x[i] = (b[i] - sum_val) / U[i, i]
        
    return x

# --- Example Execution ---
if __name__ == "__main__":
    # Define Upper Triangular Matrix U
    U = np.array([
        [2, 1, 1],
        [0, 2, 1],
        [0, 0, 1]
    ], dtype=float)
    
    # Define vector b
    b = np.array([4, 2, 2], dtype=float)

    try:
        x = backward_substitution(U, b)
        
        print("Solution vector x:")
        # Reshape for column-vector style printing
        print(x.reshape(-1, 1))
        
    except ValueError as e:
        print(e)