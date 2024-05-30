from random import randint as r
from random import shuffle as s

N = 1000
Q = 1000

a = [i for i in range(N)]
s(a)

print(f"{N} {Q}")
print(' '.join(list(map(str, a))))

for i in range(Q):
	print(N)