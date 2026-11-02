import numpy as np

def linear_forward(X, W, b):
    if X.ndim!=2 or W.ndim!=2:
        raise ValueError(f"vectorlar 2d emes genii")

    if X.shape[1] != W.shape[0]:
        raise ValueError(f"Mozg vectorlar dlinasy kelmidgo")
    
    if b.shape != (W.shape[1], ):
        raise ValueError(f"b men W shapetary kelmid") 
    
    return X@W + b

X = np.array([[1,2], [3,0], [0,1]])
W = np.array([[1,0],[2,1]])
b = np.array([1, -1])

print(linear_forward(X, W, b))

linear_forward(X, np.ones((7, 2)), b)        # W не той длины
linear_forward(X, W, np.array([1, 2, 3]))    # b не того размера
linear_forward(np.array([1, 2]), W, b)       # X одномерный  