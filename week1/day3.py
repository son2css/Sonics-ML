import numpy as np


def matmul(A, B):
    m = len(A)
    n = len(A[0])
    n1 = len(B)
    p = len(B[0])

    if n != n1:
        raise ValueError(f"False brother differ n={n} and n1={n1}")

    C = [[0 for _ in range(p)] for _ in range(m)]

    for i in range(m):
        for j in range(p):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C


def transpose(A):
    m = len(A)
    n = len(A[0])

    T = [[0 for _ in range(m)] for _ in range(n)]

    for i in range(m):
        for j in range(n):
            T[j][i] = A[i][j]
    return T


A = [[1, 2], [3, 4]]
B = [[5, 6], [7, 8]]
print(matmul(A, B))
print(np.allclose(matmul(A, B), np.array(A) @ np.array(B)))

print(matmul([[1, 2, 3]], [[4], [5], [6]]))

A2 = [[1, 2, 3], [4, 5, 6]]
print(transpose(A2))
print(np.allclose(transpose(A2), np.array(A2).T))

A3 = [[1, 2], [3, 4], [5, 6]]
B3 = [[1, 0, 2], [0, 1, 3]]
print(transpose(matmul(A3, B3)) == matmul(transpose(B3), transpose(A3)))