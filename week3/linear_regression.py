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

if __name__ == "__main__":
    from numerical_grad import gradient_central
    X = np.array([[1.0], [2.0]])
    y = np.array([5.0, 7.0])
    w = np.array([1.0])
    b = 0.0
    print("MSE:", mse_loss(X, w, b, y))          # ожидаем 20.5
    print("MAE:", mae_loss(X, w, b, y))          # ожидаем 4.5
    print("grads:", mse_gradients(X, w, b, y))
    
    np.random.seed(0)
    X = np.random.randn(50, 3)
    y = np.random.randn(50)
    w = np.random.randn(3)
    b = 0.5

    dw, db = mse_gradients(X, w, b, y)
    theta = np.append(w, b)
    numeric = gradient_central(lambda t: mse_loss(X, t[:-1], t[-1], y), theta)

    print("analytic:", np.append(dw, db))
    print("numeric: ", numeric)
    print("match:", np.allclose(np.append(dw, db), numeric))
    
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
