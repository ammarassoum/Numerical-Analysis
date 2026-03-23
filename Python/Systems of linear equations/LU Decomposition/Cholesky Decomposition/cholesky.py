import numpy as np

def cholesky(A):
    n = len(A)
    L = np.zeros_like(A)
    
    for i in range(n):
        for j in range(i+1):
            if j == i:
                # Compute the diagonal elements of L
                L[i][j] = np.sqrt(A[i][i] - np.sum(L[i][:j]**2))
            else:
                # Compute the off-diagonal elements of L
                L[i][j] = (A[i][j] - np.sum(L[i][:j]*L[j][:j])) / L[j][j]
    
    return L

# Example usage
A = np.array([[4, 6, 10], [6, 25, 19], [10, 19, 62]])
L = cholesky(A)
print(L)