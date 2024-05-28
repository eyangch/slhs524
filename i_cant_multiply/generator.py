import random

N = random.randint(900, 1000)

K = random.randint(5, N)

print(f"{N} {K}")

for i in range(N):
	print(random.randint(-100, 100), end= " ")
print()