from random import randint
ri = randint

N = ri(10000, 99999)
K = ri(100000000, 999999999)
Q = ri(10000, 100000)

print(f"{N} {K} {Q}")
for _ in range(N-1):
	print(ri(1, 800), end=' ')
print()

for _ in range(Q):
	M = ri(1, int(1000000 / Q) - 1)
	print(M)
	a = [ri(1,10)]
	for _ in range(M-1):
		x = ri(a[-1], a[-1] + int(1e3))
		a.append(x)
	for x in a:
		print(x, end=' ')
	print()