import numpy as np
from numerical_grad import derivative_central, gradient_central, max_errors
from derivatives import quad_f, quad_grad, sig_f, sig_grad, mse_loss, mse_grad

TOL = 1e-5   # допустимая относительная ошибка


def check(name, analytic, numeric):
    abs_err, rel_err = max_errors(analytic, numeric)
    print(f"{name:<10} max abs = {abs_err:.2e}   max rel = {rel_err:.2e}")
    assert rel_err < TOL, f"{name}: relative error {rel_err:.2e} is too big"


def test_derivative():
    d = derivative_central(lambda x: x**2, 2.0)
    assert abs(d - 4) < 1e-6


def test_quadratic():
    p = np.array([1.0, 2.0])
    check("quadratic", quad_grad(p), gradient_central(quad_f, p))


def test_sigmoid():
    p = np.array([0.5, 0.0])
    check("sigmoid", sig_grad(p), gradient_central(sig_f, p))


def test_mse():
    np.random.seed(0)
    X = np.random.randn(100, 8)
    y = np.random.randn(100)
    w = np.random.randn(8)
    analytic = mse_grad(X, w, y)
    numeric = gradient_central(lambda w_: mse_loss(X, w_, y), w)
    assert analytic.shape == w.shape
    check("mse", analytic, numeric)


def test_catches_wrong_gradient():
    p = np.array([1.0, 2.0])
    wrong = quad_grad(p) * 2          # специально испорченный градиент
    _,rel_err = max_errors(wrong, gradient_central(quad_f, p))
    assert rel_err> TOL


if __name__ == "__main__":
    test_derivative()
    test_quadratic()
    test_sigmoid()
    test_mse()
    test_catches_wrong_gradient()
    print("All tests passed")