import numpy as np

from numerical_grad import gradient_central

def mse_loss(X, w, y):
    e = X @ w - y
    return np.sum(e**2)/len(y)

def mse_grad(X, w, y):
    N = len(y)
    e = X @ w - y

    return (2/N) * np.transpose(X)@e

def quad_f(p):
    x, y =p
    return x**2 + 3*x*y + 2*y**2
def quad_grad(p):
    x, y = p
    return np.array([2*x + 3*y, 3*x + 4*y])

def sigmoid(z):
    return 1/ (1+ np.exp(-z))
def sig_f(p, x=2.0):
    w, b = p
    return sigmoid(w*x + b)
def sig_grad(p, x=2.0):
    s = sig_f(p, x)
    return np.array([s*(1-s)*x, s*(1-s)*1])

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
    
    print(quad_grad(np.array([1.0, 2.0])))        
    print(sig_grad(np.array([0.5, 0.0])))
    print(gradient_central(sig_f, [0.5, 0.0])) 

