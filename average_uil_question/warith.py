#!/usr/bin/python3
# Average UIL Question

from collections import Counter
from math import sqrt
import heapq

def phone(x):
    if x == 0:
        return [3, 1]
    return [x // 3 if x % 3 != 0 else x // 3 - 1, x % 3 - 1 if x % 3 != 0 else 2]

for _ in range(int(input())):
    N = int(input())
    S = str(N)
    score = 0
    
    # 1
    if N % 3 == 0: 
        score += 10
    # print(f" 1: {score}")
    
    # 2
    if N % 9 == 0: 
        score += 13
    # print(f" 2: {score}")
    
    # 3
    if N % 11 == 0: 
        score += 20
    # print(f" 3: {score}")
    
    # 4
    if N % 5 == 0: 
        score -= 2
    # print(f" 4: {score}")
    
    # 5
    if N % 10 == 0: 
        score -= 5
    # print(f" 5: {score}")
    
    # 6
    for i in range(len(S) - 2):
        if S[i] == S[i+1] and S[i] == S[i+2]:
            score -= 4
    # print(f" 6: {score}")
            
    # 7
    x = Counter(list(S))
    for i in x.keys():
        if x[i] * 2 > len(S):
            score -= int(i)
    # print(f" 7: {score}")

    # 8
    if S == S[::-1]:
        score -= 10
    # print(f" 8: {score}")
    
    # 9
    if len(S) < 5:
        print(0)
        continue
    # print(f" 9: {score}")
    
    # 10
    if len(S) > 10:
        score += len(S) - 10
    # print(f"10: {score}")
        
    # 11
    if len(x) == 10:
        score += 20
    # print(f"11: {score}")
        
    # 12
    if len(x) < 4:
        score -= 10
    # print(f"12: {score}")
        
    # 13
    dig_sum = 0
    for x in list(S):
        dig_sum += int(x)
    prime = True
    i = 2
    while i * i <= dig_sum:
        if dig_sum % i == 0:
            prime = False
        i += 1
    if prime:
        score += 30
    # print(f"13: {score}")

    # 14
    dig_sum_sum = 0
    for x in list(str(dig_sum)):
        dig_sum_sum += int(x)
    if dig_sum_sum % 2 == 0:
        score -= 7
    # print(f"14: {score}")
        
    # 15
    if str(bin(N))[2:].count('1') % 2 == 1:
        score += 17
    # print(f"15: {score}")
        
    # 16
    for i in range(len(S) - 1):
        if int(S[i]) % 2 != int(S[i+1]) % 2:
            score += 3
    # print(f"16: {score}")
            
    # 17
    dist_17 = 0
    for i in range(len(S) - 1):
        start = phone(int(S[i]))
        end = phone(int(S[i+1]))
        tmp = (start[0] - end[0])**2 + (start[1] - end[1])**2
        # print(S[i], start, S[i+1], end, tmp)
        dist_17 += sqrt(tmp)
    score += round(dist_17, 1)
    # print(f"17: {score}")
        
    # 18
    dp = {}
    dp[(S[0], None)] = 0
    for i in range(1, len(S)):
        goal = S[i]
        ndp = {}
        for (left, right), dist in dp.items():
            if left is not None:
                nstate = (goal, right)
                l, r = phone(int(left)), phone(int(goal))
                ndist = dist + sqrt( (l[0] - r[0])**2 + (l[1] - r[1])**2 )
                if nstate not in ndp or ndist < ndp[nstate]:
                    ndp[nstate] = ndist
            if right is not None:
                nstate = (left, goal)
                l, r = phone(int(goal)), phone(int(right))
                ndist = dist + sqrt( (l[0] - r[0])**2 + (l[1] - r[1])**2 )
                if nstate not in ndp or ndist < ndp[nstate]:
                    ndp[nstate] = ndist
            if right is None:
                nstate = (left, goal)
                ndist = dist
                if nstate not in ndp or ndist < ndp[nstate]:
                    ndp[nstate] = ndist
            if left is None:
                nstate = (goal, right)
                ndist = dist
                if nstate not in ndp or ndist < ndp[nstate]:
                    ndp[nstate] = ndist
        dp = ndp

    score += round(min(dp.values()), 1)
    # print(f"18: {score}")
    
    # 19
    dp = [float('inf') for _ in range(len(S))]
    dp[0] = 0
    pos = {str(digit): [] for digit in range(10)}
    for idx, num in enumerate(S):
        pos[num].append(idx)
    pq = [(0,0)] # cur score + cur pos
    while len(pq) != 0:
        cur_score, cur_pos = heapq.heappop(pq)
        # if alr at end, add the score and break
        if cur_pos == len(S) - 1:
            score += cur_score
            break
        # simulate moving right by 1
        if cur_pos + 1 < len(S):
            # actually i dont think I even need this if but whatever
            next_pos = cur_pos + 1
            next_score = cur_score + abs(int(S[cur_pos]) - int(S[next_pos]))
            if next_score < dp[next_pos]:
                # this is optimal!!
                dp[next_pos] = next_score
                heapq.heappush(pq, (next_score, next_pos))
        # now use the teleporter
        cur_digit = S[cur_pos]
        for next_pos in pos[cur_digit]:
            if next_pos > cur_pos:
                next_score = cur_score + int(cur_digit) * abs(next_pos - cur_pos)
                if next_score < dp[next_pos]:
                    # this is optimal!!
                    dp[next_pos] = next_score
                    heapq.heappush(pq, (next_score, next_pos))
    # print(f"19: {score}")

    # 20
    div3 = N % int(1e9 + 7) // 3 # no. of numbers less than N divisible by 3

    def with3(S):
        L = len(S)
        def counter(limit, pos, tight, has3, dp):
            if pos == len(limit):
                # at the end of string
                return 1 if has3 else 0
            if dp[pos][tight][has3] != -1:
                return dp[pos][tight][has3]
            ub = int(limit[pos]) if tight else 9 # if we have restriction, take it into account
            res = 0
            for dig in range(ub + 1):
                res += counter(limit, pos + 1, tight and (dig == ub), has3 or (dig == 3), dp)
            
            dp[pos][tight][has3] = res
            return res
            
        dp = [[[-1 for _ in range(2)] for _ in range(2)] for _ in range(L)]
        return counter(S, 0, 1, 0, dp)
        
    def overlap(S):
        # this is to find numbers containing 3 also divisible by it
        L = len(S)
        def counter(limit, pos, tight, has3, dig_sum, dp):
            # new arguments to keep track of digit sum and thus have divisibility by 3 tracked
            if pos == len(limit):
                return 1 if has3 and (dig_sum % 3 == 0) else 0
            if dp[pos][tight][has3][dig_sum] != -1:
                return dp[pos][tight][has3][dig_sum]
            ub = int(limit[pos]) if tight else 9
            res = 0
            for dig in range(ub + 1):
                res += counter(limit, pos + 1, tight and (dig == ub), has3 or (dig == 3), (dig_sum + dig) % 3, dp)
                # YIKES
            dp[pos][tight][has3][dig_sum] = res
            return res
        
        dp = [[[[-1 for _ in range(3)] for _ in range(2)] for _ in range(2)] for _ in range(L)]
        return counter(S, 0, 1, 0, 0, dp)
        
    score += (div3 + with3(S) - overlap(S)) % int(1e9 + 7)
    # print(f"20: {score}")
    
    print(round(score, 1))