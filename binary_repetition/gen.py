from random import randint as r

N = 1000
K = 1000

print(f"{N} {K}")

a = [r(0,1) for _ in range(N)]

print("".join(map(str,a)))