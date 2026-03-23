import numpy as np

def gaussian_elimination(a):
    # Solves a system of linear equations using Gaussian elimination
    # Input: (n+1) x (n+1) augmented matrix a
    # Output: vector x containing the solutions
    
    n = a.shape[0] - 1
    
    # Forward elimination: convert the matrix to upper triangular form
    for i in range(n):
        for j in range(i+1, n+1):
            # Compute the ratio of the jth row to the ith row
            ratio = a[j,i]/a[i,i]
            # Subtract the ith row multiplied by the ratio from the jth row
            a[j,i:] = a[j,i:] - ratio*a[i,i:]
    
    # Backward substitution: solve for the variables starting from the last row
    x = np.zeros(n+1)
    x[n] = a[n,n+1]/a[n,n]
    for i in range(n-1, -1, -1):
        x[i] = a[i,n+1]
        for j in range(i+1, n+1):
            # Subtract the known variables from the ith equation
            x[i] = x[i] - a[i,j]*x[j]
        # Divide by the coefficient of the ith variable
        x[i] = x[i]/a[i,i]
    
    return x