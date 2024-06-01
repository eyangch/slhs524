#!/usr/bin/python3

import random
ri = random.randint

N = ri(2, int(1e3))
K = ri(1, int(1e6))
print(f"{N} {K}")
for i in range(1, N+1):
	a = ri(0, int(1e3))
	print(a, end=' ')
	for _ in range(a):
		x = ri(1, N+1)
		while x == i:
			x = ri(1, N+1)
		print(x, end=' ')
	print()