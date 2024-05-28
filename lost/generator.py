import random

T = random.randint(100, 1000)
N = random.randint(500, 1000)

print(f"{T} {N}")
for i in range(T):
	A = random.randint(2, N-1)
	B = random.randint(2, N-1)
	print(f"{A} {B}")