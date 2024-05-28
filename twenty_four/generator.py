import random

T = 10
a = random.randint(1, 10)
b = random.randint(1, 10)
c = random.randint(1, 10)
d = random.randint(1, 10)
print(T)
for i in range(T):
	print(f"{a} {b} {c} {d} {i+1}")