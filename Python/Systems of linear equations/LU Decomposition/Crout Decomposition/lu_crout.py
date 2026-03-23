import numpy as np

def crout_lu(a):
    """
    Performs Crout LU decomposition on a square matrix a
    
    Input:
    a: n x n matrix
    
    Output:
    l: n x n lower triangular matrix
    u: n x n upper triangular matrix
    """
    n = len(a)
    l = np.zeros((n, n))
    u = np.zeros((n, n))
    
    # Initialize the diagonal elements of L to 1
    for i in range(n):
        l[i, i] = 1.0
    
    # Compute the elements of L and U
    for j in range(n):
        # Compute the jth column of U
        for i in range(j, n):
            sum = 0.0
            for k in range(j):
                sum += l[i, k]*u[k, j]
            u[i, j] = a[i, j] - sum
        
        # Compute the jth row of L
        for i in range(j+1, n):
            sum = 0.0
            for k in range(j):
                sum += l[j, k]*u[k, i]
            l[j, i] = (a[j, i] - sum)/u[j, j]
    
    return l, u