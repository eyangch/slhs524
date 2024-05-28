#!/usr/bin/python3
# LLLL

N = int(input())
for _ in range(N):
    A, S = map(int, input().split())
    print("L" if A <= S else "W", end='')
print()
