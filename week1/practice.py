import numpy as np

a1 = np.ones(12).reshape(4,3)
print(a1.shape, a1.ndim, a1.size)

a2 = np.arange(24).reshape(2,3,4)
print(a2.shape)

a2.reshape(4, -1)
print(a2.shape)

v = np.array((10, 20, 30, 40, 50)).reshape(5,1)
print(v.shape)

v.reshape(1,5)
print(v.shape)

v1= np.zeros(5, 7).reshape(6, 6) #will not work
print(v1.shape)