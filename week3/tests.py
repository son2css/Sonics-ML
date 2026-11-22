import numpy as np
import linear_regression as linreg
import logistic_regression as logreg
from numerical_grad import gradient_central, max_errors

TOL = 1e-5

def check_grad(name, analytic, numeric):
    abs_error, rel_error = max_errors(analytic, numeric)
    print(f"{name:<22} max abs = {abs_error:.2e} max rel = {rel_error:.2e}")
    assert rel_error<TOL, f"{name}: relative error {rel_error:.2e} is too big"

def test_linear_shapes():
    X, y = linreg.make_data()
    w, b = np.array([1.0]), 0.0
    
    assert X.shape == (100, 1)
    assert linreg.predict(X, w, b).shape == y.shape
    
    dw, db = linreg.mse_gradients(X, w, b, y)
    assert dw.shape == w.shape
    assert np.ndim(db) == 0
    
def test_linear_loss_decreases():
    X, y = linreg.make_data()
    w, b, losses = linreg.fit_gd(X, y, lr=0.01, steps=200)
    
    assert losses[-1]<losses[0]

def test_linear_gradients():
    np.random.seed(1)
    X = np.random.randn(30, 3)
    y = np.random.randn(30)
    
    for i in range(5):
        w = np.random.randn(3)
        b = np.random.randn()
        
        dw, db = linreg.mse_gradients(X, w, b, y)
        numeric = gradient_central(lambda t: linreg.mse_loss(X, t[:-1], t[-1], y), np.append(w, b))
        check_grad(f"linear grad #{i+1}", np.append(dw, db), numeric)
        
def test_logistic_proba_range():
    X, y = logreg.make_data()
    p = logreg.predict_proba(X, np.array([1.0, 1.0]), 0.0)
    assert p.shape == y.shape
    
    assert np.all((p>0) & (p<1))

def test_logistic_gradients():
    X, y = logreg.make_data()
    np.random.seed(2)
    for i in range(5):
        w = np.random.randn(2)
        b = np.random.randn()
        
        dw, db = logreg.bce_gradients(X, w, b, y)
        numeric = gradient_central(lambda t: logreg.bce_loss(X, t[:-1], t[-1], y), np.append(w, b))
        check_grad(f"logistic grad #{i+1}", np.append(dw, db), numeric)
        
def test_bce_no_nan():
    X, y = logreg.make_data()
    loss = logreg.bce_loss(X, np.array([100.0, 100.0]), 0.0, y)
    assert np.isfinite(loss)

def test_metrics():
    y_true = np.array([1]*15 + [0]*10 + [1]*5 + [0]*170)
    y_pred = np.array([1]*15 + [1]*10 + [0]*5 + [0]*170)
    p, r, f1 = logreg.precision_recall_f1(y_true, y_pred)
    
    assert abs(p - 0.6) < 1e-9
    assert abs(r - 0.75) < 1e-9
    assert abs(f1 - 2/3) < 1e-9

if __name__ == "__main__":
    test_linear_shapes()
    test_linear_loss_decreases()
    test_linear_gradients()
    test_logistic_proba_range()
    test_logistic_gradients()
    test_bce_no_nan()
    test_metrics()
    print("All tests passed") 