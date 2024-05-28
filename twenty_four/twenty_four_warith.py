#!/usr/bin/python3
# 24
# what the freak

from itertools import permutations

def conv(n):
    ans = ""
    if n >= 16:
        ans += str(n // 16)
        n %= 16
    else:
        ans += "0"
    if n >= 4:
        ans += str(n // 4)
        n %= 4
    else:
        ans += "0"
    return ans + str(n)

N = int(input())
for _ in range(N):
    a, b, c, d, K = map(str, input().split())
    K = int(K)
    nums = [a, b, c, d]
    ops = ["+", "-", "*", "/"]
    works = False
    for i in range(64):
        ww = [] # i got bored
        for x in conv(i):
            ww.append(ops[ord(x) - 48])
        for p in permutations(nums):
            # every situation should be
            # ( ( a @ b ) @ c ) @ d
            # ( a @ ( b @ c ) ) @ d
            # ( a @ b ) @ ( c @ d )
            # a @ (b @ (c @ d))
            # a @ ((b @ c) @ d)
            alpha = "((" + p[0] + ww[0] + p[1] + ")" + ww[1] + p[2] + ")" + ww[2] + p[3]
            beta = "(" + p[0] + ww[0] + "(" + p[1] + ww[1] + p[2] + "))" + ww[2] + p[3]
            gamma = "(" + p[0] + ww[0] + p[1] + ")" + ww[1] + "(" + p[2] + ww[2] + p[3] + ")"
            urmom1 = p[0] + ww[0] + "(" + p[1] + ww[1] + "(" + p[2] + ww[2] + p[3] + ")" + ")"
            urmom2 = p[0] + ww[0] + "((" + p[1] + ww[1] + p[2] + ")" + ww[2] + p[3] + ")"
            try:
                works |= eval(alpha) == K
                # print(alpha, eval(alpha))
            except:
                pass
            try:
                works |= eval(beta) == K
                # print(beta, eval(beta))
            except:
                pass
            try:
                works |= eval(gamma) == K
                # print(gamma, eval(gamma))
            except:
                pass
            try:
                works |= eval(urmom1) == K
                # print(gamma, eval(gamma))
            except:
                pass
            try:
                works |= eval(urmom2) == K
                # print(gamma, eval(gamma))
            except:
                pass
            
    print("YES" if works else "NO")