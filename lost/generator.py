import random

T = random.randint(50, 100)
N = random.randint(50, 100)

print(f"{T} {N}")
for i in range(T):
	A = random.randint(2, N-1)
	B = random.randint(2, N-1)
	print(f"{A} {B}")