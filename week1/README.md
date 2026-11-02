# Hello everyone!

## control.py is my mini/check project for ML.

## What does my project do?
My project is about Linear Forward. Linear forward computes new features
from input features: each output is a weighted sum of the inputs
(weights from W) plus a bias b. Now W and b are random, but later
they will be learned during training to give the right output.

## Shapes
- `X: (5, 8)` — our input. 5 sentences, each described by 8 features.
- `W: (8, 4)` — our weight matrix. It maps the 8-dimensional input space into a 4-dimensional output space.
- `b: (4,)` — our bias vector, 4 numbers, one per output. It is added to every row (broadcasting).
- `y: (5, 4)` — our output, computed as `X @ W + b`. The same 5 sentences, but each with 4 new features.
