import numpy as np
import matplotlib.pyplot as plt

def make_data(n = 100, seed = 42):
    np.random.seed(seed)
    x = np.random.uniform(0, 10,  size=n)
    noise = np.random.randn(n)
    
    y = 3*x + 2 + noise
    X = x.reshape(-1, 1)
    return X, y

def predict(X, w, b):
    return X@w + b

def mse_loss(X, w, b, y):
    e = predict(X, w, b) - y
    return np.mean(e ** 2)

def mae_loss(X, w, b, y):
    e= predict(X, w, b) - y
    return np.mean(np.abs(e))


def mse_gradients(X, w, b, y):
    N = len(y)
    e = predict(X, w, b) - y
    dw = (2/N) * np.transpose(X) @ e
    db = (2/N) * np.sum(e)
    return dw, db

def fit_gd(X, y, lr =0.01, steps = 1000):
    w = np.zeros(X.shape[1])
    b= 0.0
    losses = []
    
    for step in range(steps):
        dw, db = mse_gradients(X, w, b, y)
        w = w - lr*dw
        b = b - lr*db
        
        losses.append(mse_loss(X, w, b, y))
    return w, b, losses
        

if __name__ == "__main__":
    X, y = make_data()

    for lr in [0.001, 0.01, 0.1]:
        w, b, losses = fit_gd(X, y, lr=lr, steps=1000)
        print(f"lr={lr}:  w={w}  b={b}  last loss={losses[-1]}")
        plt.plot(losses, label=f"lr={lr}")

    plt.ylim(0, 50)        
    plt.xlabel("step")
    plt.ylabel("MSE")
    plt.title("Loss curve for different learning rates")
    plt.legend()
    plt.show()