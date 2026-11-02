import math
import numpy as np

def dot(a, b):
    if(len(a)!=len(b)):
        raise ValueError(f"Vectors must have same length, got {len(a)} and {len(b)}")
    total = 0;
    for x, y in zip(a, b):
        total = total + x*y
    return total
def vector_norm(v):
    total = 0
    for x in v:
        total+=x*x
    return math.sqrt(total)
def cosine_similarity(a, b):
    return dot(a,b)/(vector_norm(a)*vector_norm(b))

a = [1,2,3]
b= [4,5,6]
print(dot(a,b), np.dot(a,b))
print(vector_norm(a), np.linalg.norm(a))
print(cosine_similarity(a,b))
print(vector_norm([6, 8]))                      # 10.0
print(cosine_similarity([3, 4], [4, 3]))        # 0.96
print(cosine_similarity([1, 0, 2], [0, 5, 0]))  # 0.0
print(cosine_similarity([1, 2], [2, 4]))        # 1.0  (same direction)
print(cosine_similarity([1, 2], [-1, -2]))      # -1.0 (opposite)