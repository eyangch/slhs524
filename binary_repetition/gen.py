from random import randint as r

tot = 1000

N = 100000
K = 1000000000

print(f"{N} {K}")

a = [i%2 for i in range(N)]

print("".join(map(str,a)))