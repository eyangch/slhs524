from math import comb
from functools import lru_cache

MOD = 1000000007

@lru_cache(maxsize=None)
def A000629(n): 
	return (1+sum(comb(n, j)*A000629(j) % MOD for j in range(n)) if n else 1) % MOD

for i in range(100):
	print(A000629(i))