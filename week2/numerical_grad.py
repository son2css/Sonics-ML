import numpy as np

def deriviative_central(f, x, eps = 1e-5):
    return (f(x + eps) - f(x -eps))/(2*eps)


def gradient_central(f, params, eps= 1e-5):
    params = np.array(params, dtype = float)
    grad = np.zeros_like(params)
    
    for i in range(len(params)):
        p_plus = params.copy()
        p_minus = params.copy()
        
        p_plus[i] += eps
        p_minus[i] -= eps
        
        grad[i] = (f(p_plus) - f(p_minus))/(2*eps)
        
    return grad

if __name__ == "__main__":
    print(deriviative_central(lambda x: x**2, 2.0))

    def f4(p):
        x, y = p
        
        return x**2 + 3*x*y + 2*y**2
    print(gradient_central(f4, [1,2]))

    def neuron_loss(p):
        w, b = p
        
        z = w*2 + b
        a = max(0, z)
        
        return (a-3) ** 2
    print(gradient_central(neuron_loss, [0.5, 0]))
    
    # эксперимент: как размер eps влияет на точность
    # f(x) = x³, точная производная в x = 2 равна 12
    f3 = lambda x: x**3
    for eps in [1e-1, 1e-3, 1e-5, 1e-8, 1e-12, 1e-15]:
        central = (f3(2 + eps) - f3(2 - eps)) / (2 * eps)
        forward = (f3(2 + eps) - f3(2)) / eps
        print(f"eps={eps:.0e}  central={central:.10f}  forward={forward:.10f}")

        