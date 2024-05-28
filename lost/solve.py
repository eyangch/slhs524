#!/usr/bin/python3

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

T, N = map(int, input().split())
for _ in range(T):
	A, B = map(int, input().split())
	print(min(A + B, A * B // gcd(A, B)))