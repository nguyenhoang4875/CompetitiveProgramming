from random import randint
import numpy as np
import string
import random

N = randint(90, 100)
S = ""
for _ in range(100):
    S += "abc"
print(N)
for i in range(N):
    tmp = randint(1, 3)
    if tmp == 1:
        res = ''.join(random.choices(string.ascii_lowercase , k=randint(1, N)))
        print(res)
    else:
        u = randint(1, N-1)
        v = randint(u+1, N)
        # print(u, v)
        print(S[u:v])
