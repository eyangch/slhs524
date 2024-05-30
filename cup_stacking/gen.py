#!/usr/bin/env python3
from random import randint

n = 1000
a = [randint(1, 1_000_000_000_000_000_000) for i in range(n*(n+1)>>1)]
print(n)
print(' '.join(map(str, a)))
