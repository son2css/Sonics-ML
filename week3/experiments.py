import numpy as np
import linear_regression as linreg
import logistic_regression as logreg
import matplotlib.pyplot as plt

def train_val_test_split(X, y, val=0.15, test  = 0.15, seed = 0):
    np.random.seed(seed)
    idx = np.random.permutation(len(y))
    n_test = int(len(y) * test)
    n_val = int(len(y) * val)
    
    test_idx = idx[:n_test]
    val_idx = idx[n_test:n_test + n_val]
    train_idx = idx[n_test + n_val:]
    
    return X[train_idx], y[train_idx], X[val_idx], y[val_idx], X[test_idx], y[test_idx]

def standardize_fit(X_train):
    mean = X_train.mean(axis=0)
    std = X_train.std(axis=0)
    
    return mean, std

def standardize_apply(X, mean, std):
    return (X - mean) / std

if __name__ == "__main__":
    import warnings
    warnings.filterwarnings("ignore")
    
    X, y = linreg.make_data()
    Xtr, ytr, Xva, yva, Xte, yte = train_val_test_split(X, y)
    print("train/val/test:", Xtr.shape, Xva.shape, Xte.shape)
    
    mean, std = standardize_fit(Xtr)
    Xtr_s = standardize_apply(Xtr, mean, std)
    Xva_s = standardize_apply(Xva, mean, std)
    print("after scaling: mean", Xtr_s.mean(axis=0), " std", Xtr_s.std(axis=0))
    
    for scaled in [False, True]:
        for lr in [0.001, 0.01, 0.1]:
            A, V = (Xtr_s, Xva_s) if scaled else (Xtr, Xva)
            w, b, losses = linreg.fit_gd(A, ytr, lr = lr, steps= 1000)
            print(f"scaled={scaled} lr={lr}: train MSE={losses[-1]:.3f} val MSE={linreg.mse_loss(V, w, b, yva):.3f}")
    
    X, y = logreg.make_data()
    Xtr, ytr, Xva, yva, Xte, yte = train_val_test_split(X, y)
    print("classes in test:", np.bincount(yte))
    
    w, b, losses = logreg.fit_gd(Xtr, ytr)
    y_pred = logreg.predict(Xte, w, b)
    print("test accuracy:", np.mean(y_pred == yte))
    print("test P, R, F1:", logreg.precision_recall_f1(yte, y_pred))
    
    X, y = linreg.make_data()
    Xtr, ytr, Xva, yva, Xte, yte, = train_val_test_split(X, y)
    mean, std = standardize_fit(Xtr)
    Xtr_s = standardize_apply(Xtr, mean, std)
    Xva_s = standardize_apply(Xva, mean, std)
    
    for bs in [1, 16, 70]:
        w, b, losses = linreg.fit_minibatch(Xtr_s, ytr, lr= 0.05, epochs=20, batch_size=bs)
        steps = 20* int(np.ceil(len(ytr) / bs))
        print(f"batch={bs}: steps={steps} train MSE={losses[-1]:.3f} val MSE={linreg.mse_loss(Xva_s, w, b, yva):.3f}")
        plt.plot(losses, label=f"batch={bs}")
        
    plt.yscale("log")
    plt.xlabel("epoch")
    plt.ylabel("train MSE")
    plt.title("Batch size comparison")
    plt.legend()
    plt.show()
        