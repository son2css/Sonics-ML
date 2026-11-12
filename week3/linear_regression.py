import numpy as np
import matplotlib.pyplot as plt

def make_data(n = 100, seed = 42):
    np.random.seed(seed)
    x = np.random.uniform(0, 10, size=n)
    noise = np.random.randn(n)
    
    y = 3*x + 2 + noise
    X = x.reshape(-1, 1)
    return X, y

def predict(X, w, b):
    return X@w + b

if __name__ == "__main__":
    X, y = make_data()
    print("X:", X.shape, "y:", y.shape)
    
    w_true, b_true = np.array([3.0]), 2.0
    w_bad, b_bad = np.array([1.0]), 0.0
    
    print("predictions:", predict(X, w_true, b_true).shape)
    
    plt.scatter(X[:, 0], y, s=10, label="data")
    xs = np.linspace(0, 10, 100).reshape(-1, 1)
    plt.plot(xs[:, 0], predict(xs, w_true, b_true), label="true: 3x+2")
    plt.plot(xs[:, 0], predict(xs, w_bad, b_bad), label="bad guess: 1x + 0")
    
    plt.legend()
    plt.show()
    