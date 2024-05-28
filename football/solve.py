#!/usr/bin/python3
# Football

N = int(input())
for _ in range(N):
    S = input().lower()
    if "tony" in S:
        if "cs" in S:
            print("locked in")
        else:
            print("football")
    else:
        print("I'm not going to state aight")