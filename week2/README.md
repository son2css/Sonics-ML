## What this project does
An **analytic gradient** is calculated with a formula that we derive by hand
(using derivative rules and the chain rule).
A **numeric gradient** is calculated by the principle "if I move the input
a little bit, how much does the output change?" (central difference).
We compare them: if they are equal, our hand-derived formula is correct.
This is called a **gradient check**, and it catches mistakes in the math.

## Choice of ε
ε is the small step we use to move the input in the central difference:
`(f(x + ε) − f(x − ε)) / (2ε)`.
We use **ε = 1e-5**, because it gives the most accurate result.
- If ε is too big (1e-1, 1e-3), the function curves inside the step,
  so we measure an average slope instead of the slope at the point.
- If ε is too small (1e-12, 1e-15), `f(x + ε)` and `f(x − ε)` are almost equal.
  The computer keeps only ~16 digits, so the subtraction loses the useful
  digits and only rounding noise is left. Then dividing by a tiny 2ε makes
  this noise even bigger.

## Failed experiment
We tested `f(x) = x³` at `x = 2` (true derivative = 12) with different ε:

    eps=1e-01  central=12.0100000000  forward=12.6100000000
    eps=1e-03  central=12.0000010000  forward=12.0060010000
    eps=1e-05  central=12.0000000002  forward=12.0000600003
    eps=1e-08  central=11.9999998827  forward=11.9999999271
    eps=1e-12  central=12.0010668070  forward=12.0010668070
    eps=1e-15  central=11.9904086660  forward=10.6581410364

What we learned:
- A smaller ε is **not** always better: at 1e-12 and 1e-15 the result got
  worse because of rounding errors.
- Central difference is more accurate than forward difference for almost
  every ε. With ε = 1e-15, forward difference was wrong by more than 11%.