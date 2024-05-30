#!/usr/bin/env python3

from random import randint

n = 1500
a = [randint(1, 1_000_000_000) for i in range(n)]
print(n)
print(' '.join(map(str, a)))
