import numpy as np

from numerical_grad import gradient_central

def mse_loss(X, w, y):
    e = X @ w - y
    return np.sum(e**2)/len(y)

def mse_grad(X, w, y):
    N = len(y)
    e = X @ w - y

    return (2/N) * np.transpose(X)@e

if __name__ == "__main__":
    X = np.array([[1,2], [3,1]], dtype = float)
    y = np.array([3,1], dtype = float)
    w = np.array([1,0], dtype = float)
    
    print("L=", mse_loss(X, w, y))
    print("analytic:", mse_grad(X, w, y))
    print("numeric: ", gradient_central(lambda w_:mse_loss(X, w_, y), w))
    
    np.random.seed(0)
    X= np.random.randn(100, 8)
    y = np.random.randn(100)
    w = np.random.randn(8)
    
    g_analytic = mse_grad(X, w, y)
    g_numeric = gradient_central(lambda w_: mse_loss(X, w_, y), w)
    print("shape:", g_analytic.shape)
    print("match:", np.allclose(g_analytic, g_numeric))
    

