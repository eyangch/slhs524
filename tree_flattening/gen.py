#!/usr/bin/env python3

from random import randint

n = 10
print(n)
a = [randint(1, 10) for i in range(n-2)]

# from cses prufer code
d = [1] * (n + 1)
for v in a:
    d[v] += 1
 
p = 1
while d[p] != 1:
    p += 1
l = p
 
for v in a:
    print(l, v)
    d[v] -= 1
    if d[v] == 1 and v < p:
        l = v
    else:
        p += 1
        while d[p] != 1:
            p += 1
        l = p
 
print(l, n)
