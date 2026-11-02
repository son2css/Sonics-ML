import numpy as np

a1 = np.arange(25).reshape(5,5)
print("a1:", a1.shape, a1.ndim)

a2 = np.arange(18).reshape(6,3)
print("a2:", a2.shape, a2.ndim)

a3 = np.array([1.0, 5.0])
print("a3:", a3.shape, a3.ndim)

a4 = np.zeros((64, 64, 3))
print("a4:", a4.shape, a4.ndim)

a5 = np.zeros((10, 64, 64, 3))
print("a5:", a5.shape, a5.ndim)

a6 = np.zeros((5, 7, 16))
print("a6:", a6.shape, a6.ndim)

a7 = np.zeros((30, 4))
print("a7:", a7.shape, a7.ndim)