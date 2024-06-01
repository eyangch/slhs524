#!/usr/bin/python3
# walrus moment

def flatten(N, X, Y):
    dist, S = 0, 2**(N-1)
    while S > 0:
        rx = (X & S) > 0
        ry = (Y & S) > 0
        dist += S**2 * ( (3*rx) ^ ry)
        if ry == 0:
            if rx == 1:
                X, Y = S - X - 1, S - Y - 1
            X, Y = Y, X
        S >>= 1
    return dist
    
def reverse(N, D):
    x, y = 0, 0
    t = D
    s = 1
    while s < 2**N:
        rx = 1 & (t // 2)
        ry = 1 & (t ^ rx)
        if ry == 0:
            if rx == 1:
                x, y = s - x - 1, s - y - 1
            x, y = y, x
        x += s * rx
        y += s * ry
        t >>= 2
        s <<= 1
    print(x, y)

N = int(input())
Q = int(input())
for _ in range(Q):
    X, Y, D = map(int, input().split())
    start = flatten(N, X, Y)
    reverse(N, flatten(N, X, Y) + D)