# Week 3: Results

## 1. Linear regression: learning rate
Data: `y = 3x + 2 + noise`, 100 points, raw features (x from 0 to 10), batch GD, 1000 steps.

| lr | learned w | learned b | final MSE | result |
|---|---|---|---|---|
| 0.001 | 3.106 | 1.227 | 1.084 | too slow, did not reach the bottom |
| 0.01 | 2.955 | 2.208 | 0.807 | converged |
| 0.1 | nan | nan | nan | diverged |

True parameters: w = 3, b = 2. The model does not find them exactly because of the noise;
on these 100 points the line 3x + 2 has MSE 0.825, while the learned line has 0.807.

## 2. Standardization × learning rate
Split: 70 / 15 / 15 (train / val / test). Mean and std are computed on train only.

| scaled | lr | train MSE | val MSE |
|---|---|---|---|
| no | 0.001 | 1.069 | 1.330 |
| no | 0.01 | 0.779 | 1.288 |
| no | 0.1 | nan | nan |
| yes | 0.001 | 6.252 | 7.834 |
| yes | 0.01 | 0.779 | 1.289 |
| yes | 0.1 | 0.779 | 1.289 |

## 3. Batch size
Standardized features, lr = 0.05, 20 epochs.

| batch size | steps | train MSE | val MSE |
|---|---|---|---|
| 1 (SGD) | 1400 | 0.846 | 1.372 |
| 16 (mini-batch) | 100 | 0.780 | 1.298 |
| 70 (full batch) | 20 | 5.214 | 6.553 |

## 4. Logistic regression
Data: two 2D clouds around (−2, −2) and (2, 2), 100 points each. lr = 0.1, 1000 steps.

- learned w = [2.03, 2.20], b = −0.248
- BCE: 0.531 → 0.0096
- test set: 13 points of class 0, 17 of class 1
- test accuracy = 1.0, precision = 1.0, recall = 1.0, F1 = 1.0

## 5. Gradient checks
Analytic vs numeric gradient (central difference, ε = 1e-5), 5 random parameter sets per model.
All 10 checks pass; the largest relative error is 1.24e-10 (tolerance 1e-5).

## 6. Mistakes I made
- `mse_loss` returned the mean of errors instead of squared errors: +2 and −2 cancel out.
- `mse_gradients` without `2/N`: correct by accident when N = 2, caught by the test with N = 50.
- `predict` with a reversed condition: accuracy close to 0, the model answered the opposite.
- `np.random.randn(seed)` instead of `np.random.seed(seed)`: data changed on every run.
- `seed = 0.0`: NumPy needs an integer seed.
- `np.array(w, b)` instead of `np.append(w, b)`: the second argument is read as a data type.

## 7. Observations
- With raw features (x from 0 to 10), lr = 0.1 diverges: the slope is steep,
  so each step jumps over the minimum and the loss grows to infinity (nan).
  After standardization (mean 0, std 1) the slope is gentler, and lr = 0.1
  trains well. Standardization does not change the best MSE (0.779),
  it only makes the minimum easier to reach.
- Validation MSE (1.29) is higher than train MSE (0.78). The model fits w and b
  on the train points, while validation points are new to it. The validation
  set is also small (15 points), so a few noisy points change its MSE a lot.
- Batch size: with the same amount of work (20 epochs), batch = 70 made only
  20 steps and did not reach the minimum (MSE 5.2). Mini-batch (16) made 100 steps
  and reached the minimum smoothly. SGD (batch = 1) reached the minimum after
  the first epoch, but kept jumping around it because each step listens
  to only one point.

## 8. Conclusions
- Standardization lets us use a larger learning rate without divergence.
- Accuracy alone can be misleading: a lazy spam filter that never says "spam"
  gets 90% accuracy but 0 recall. Precision, recall and F1 show the real quality,
  and which one matters more depends on which mistake is more expensive.
- A numerical gradient check catches mistakes in hand-derived formulas.
  A missing 2/N looked correct on a small example and was caught only by the test.
- Train / validation / test: the model learns only on train; we use validation
  to choose hyperparameters (learning rate, number of steps); test is checked once
  at the end. Mean and std for standardization are computed on train only,
  otherwise information from test leaks into training.
- Mini-batch is the best trade-off: cheap steps and a fairly accurate direction.