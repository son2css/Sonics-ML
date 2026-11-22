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
def confusion(y_true, y_pred):
    tp = np.sum((y_pred == 1) & (y_true == 1))
    fp = np.sum((y_pred == 1) & (y_true == 0))
    fn = np.sum((y_pred == 0) & (y_true == 1))
    tn = np.sum((y_pred == 0) & (y_true == 0))
    
    return tp, fp, fn, tn

def precision_recall_f1(y_true, y_pred):
    tp, fp, fn, tn = confusion(y_true, y_pred)
    
    precision = tp/(tp + fp) if tp + fp>0 else 0.0
    recall = tp/(tp + fn) if tp + fn >0 else 0.0
    f1 = 2 * precision * recall / (precision + recall) if precision + recall>0 else 0.0
    
    return precision, recall, f1

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
    
    y_true = np.array([1]*15 + [0]*10 + [1]*5 + [0]*170)
    y_pred = np.array([1]*15 + [1]*10 + [0]*5 + [0]*170)
    
    print("confusion:", confusion(y_true, y_pred))
    print("P, R, F1:", precision_recall_f1(y_true, y_pred))
    lazy = np.zeros(200, dtype=int)
    print("lazy P, R, F1:", precision_recall_f1(y_true, lazy))
    
    print("model P, R, F1:", precision_recall_f1(y, predict(X, w, b)))    
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

