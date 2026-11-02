import numpy as np

def linear_forward(X, W, b):
    if X.ndim!=2 or W.ndim!=2:
        raise ValueError(f"Mozg X{X.ndim} pen W{W.ndim} sai kelmeidy")
    if X.shape[1] != W.shape[0]:
        raise ValueError(f"Genii qate sende X.shape ={X.shape[1]}pen W.shape ={W.shape[0]} ostarynan")
    if b.shape!= (W.shape[1],):
        raise ValueError(f"eheh blin, sende b.shape ={b.shape} kelmid W.shape ={(W.shape[1],)} men")
    
    return X@W + b

np.random.seed(42)
X = np.random.randn(5, 8)
W = np.random.randn(8, 4)
b = np.random.randn(4, )

print(f"X tyn shape: {X.shape}")
print(X)

print(f"W dyn shape: {W.shape}")
print(W)

print(f"b nyn shape: {b.shape}")
print(b)

y= linear_forward(X, W, b)

print(f"y tyn shape: {y.shape}")
print(y)

assert y.shape == (5,4)
assert np.allclose(y, X@W + b)

y1 = linear_forward(X[:1], W, b)
assert y1.shape == (1, 4)

try:
    linear_forward(X, np.random.randn(7, 4), b)
    assert False, "there is no mistakes said, but it must be!"
except ValueError:
    pass

print("All test cases passedd!!!")