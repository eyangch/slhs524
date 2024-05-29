import random

N = 5
L = 100
V = 200

ans = 0
tot = 0

for i in range(1000000):
	l = [random.random() * L for _ in range(N)]
	d = [random.randint(0, 1) for _ in range(N)]
	cur = 0
	for j in range(len(l)):
		if d[j] == 0:
			cur = max(cur, l[j]/V)
		else:
			cur = max(cur, (L-l[j])/V)
	ans += cur
	tot += 1

print(ans / tot)