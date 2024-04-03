from random import randint
import numpy as np
import string
import random

N = randint(5, 10)
T = randint(4, 10)

print(N, end= " ")
print(T)

num = 0
TC = ""
MAX = 100;

for _ in range(N):
    A = randint(num, MAX)
    num = A + 1
    MAX += 1
    S = randint(0, 10)
    TC += str(A) + " " + str(S) + "\n"
print(TC)
