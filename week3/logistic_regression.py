import numpy as np
import matplotlib.pyplot as plt

def make_data(n=100, seed=0):
    np.random.seed(seed)
    x0 = np.random.randn(n, 2) + np.array([-2, -2])
    x1 = np.random.randn(n, 2) + np.array([2,2])
    X = np.vstack([x0, x1])
    y = np.array([0]*n + [1]*n)
    return X, y

def sigmoid(z):
    return 1/(1 + np.exp(-z))

def predict_proba(X, w, b):
    return sigmoid(X@w + b)

def predict(X, w, b, threshold = 0.5):
    return (predict_proba(X, w, b) >= threshold).astype(int)

if __name__ == "__main__":
    X, y = make_data()
    print("X:", X.shape, "y:", y.shape)
    
    w = np.array([1.0, 1.0])
    b= 0.0
    
    print("proba:", predict_proba(X[:3], w, b))
    print("pred:", predict(X[:3], w, b))
    print("true: ", y[:3])
    print("accuracy:", np.mean(predict(X, w, b) == y))
    
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap="bwr", s=15)
    plt.xlabel("features 1")
    plt.ylabel("features 2")
    plt.title("Two classes")
    plt.show()
