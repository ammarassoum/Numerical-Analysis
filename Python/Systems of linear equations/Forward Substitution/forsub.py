import numpy as np

def forward_substitution(L, b):
    """
    Solves Lx = b using Forward Substitution.
    
    Parameters:
    L (numpy.ndarray): Lower triangular matrix (n x n)
    b (numpy.ndarray): Right-hand side vector (n)
    
    Returns:
    x (numpy.ndarray): Solution vector
    """
    
    # Get number of rows
    n = len(b)
    
    # Initialize solution array with zeros
    x = np.zeros(n)
    
    # Iterate over rows
    for i in range(n):
        sum_val = 0
        
        # Iterate over columns before the diagonal
        for j in range(i):
            sum_val += L[i, j] * x[j]
        
        # Check for singularity
        if L[i, i] == 0:
            raise ValueError("Matrix is singular (zero on diagonal).")
            
        # Compute the value of x[i]
        x[i] = (b[i] - sum_val) / L[i, i]
        
    return x

# --- Example Execution ---
if __name__ == "__main__":
    # Define Lower Triangular Matrix L
    L = np.array([
        [3, 0, 0],
        [2, 4, 0],
        [1, 2, 5]
    ], dtype=float)
    
    # Define vector b
    b = np.array([6, 8, 10], dtype=float)

    try:
        # Call the function
        x = forward_substitution(L, b)
        
        print("Solution vector x:")
        # Reshape to column vector style for cleaner printing
        print(x.reshape(-1, 1))
        
    except ValueError as e:
        print(e)