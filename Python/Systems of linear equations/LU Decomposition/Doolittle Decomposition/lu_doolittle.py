import numpy as np

def lu_decomposition(A):
    # Perform Doolittle LU decomposition of matrix A
    n = len(A)
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    for i in range(n):
        for j in range(i, n):
            # Compute upper triangular matrix U
            sum = 0
            for k in range(i):
                sum += L[i][k] * U[k][j]
            U[i][j] = A[i][j] - sum

        for j in range(i, n):
            # Compute lower triangular matrix L
            if i == j:
                L[i][j] = 1
            else:
                sum = 0
                for k in range(i):
                    sum += L[j][k] * U[k][i]
                L[j][i] = (A[j][i] - sum) / U[i][i]

    return L, U

# Example usage
A = np.array([[4, 6, 10], [6, 25, 19], [10, 19, 62]])

L, U = lu_decomposition(A)

# Print L and U matrices
print("L matrix:")
print(L)
print("U matrix:")
print(U)