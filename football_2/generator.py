from random import randint

T = 20
print(T)

r = 50

for i in range(T):
	N = randint(1000, 2000)
	K = randint(1000, 2000)
	print(f"{N} {K} {randint(-r, r)} {randint(-r, r)}")
	for i in range(N):
		print(f"{randint(-r, r)} {randint(-r, r)}")