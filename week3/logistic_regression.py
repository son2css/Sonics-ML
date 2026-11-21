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

def bce_loss(X, w, b, y, eps = 1e-12):
    p = predict_proba(X, w, b)
    p = np.clip(p, eps, 1-eps)
    
    return -np.mean(y * np.log(p) + (1-y) * np.log(1-p))

    
def bce_gradients(X, w, b, y):
    N = len(y)
    p = predict_proba(X, w, b)
    dw = (1/N) * np.transpose(X) @ (p-y)
    db = (1/N) * np.sum(p-y)
    
    return dw, db

def fit_gd(X, y, lr = 0.1, steps = 1000):
    w= np.zeros(X.shape[1])
    b = 0.0
    losses = []
    
    for step in range(steps):
        dw, db = bce_gradients(X, w, b, y)
        w = w- lr*dw
        b = b - lr* db
        
        losses.append(bce_loss(X, w, b, y))
    return w, b, losses

if __name__ == "__main__":
    from numerical_grad import gradient_central
    
    X, y = make_data()
    
    w0, b0 = np.array([0.3, -0.2]), 0.1
    dw, db = bce_gradients(X, w0, b0, y)
    
    numeric = gradient_central(lambda t: bce_loss(X, t[:-1], t[-1], y), np.append(w0, b0))
    print("grad match:", np.allclose(np.append(dw, db), numeric))
    
    w, b, losses = fit_gd(X, y, lr = 0.1, steps = 1000)
    print("learned w:", w, "b:", b)
    print("loss: first", losses[0], " last", losses[-1])
    print("accuracy:", np.mean(predict(X, w, b) == y))
    
    plt.figure()
    plt.plot(losses)
    plt.xlabel("step")
    plt.ylabel("BCE")
    plt.title("Loss curve")
    
    plt.figure()
    plt.scatter(X[:, 0], X[:, 1], c=y, cmap="bwr", s=15)
    xs = np.linspace(-5, 5, 100)
    plt.plot(xs, -(w[0]* xs + b)/w[1], "k-", label = "decision boundary")
    plt.legend()
    plt.title("Decision boundary")
    plt.show()

