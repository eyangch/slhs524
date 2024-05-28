#!/usr/bin/python3
# I can't multiply

N, K = map(int, input().split())
A = [*map(int, input().split())]

dp = [ [-float('inf') for _ in range(K+1)] for _ in range(N+1)]
dp2 = [ [-float('inf') for _ in range(K+1)] for _ in range(N+1)]
# dp2 is because we have to keep track of really negative products
# since like -100 times -100 is 10,000 which is rly positive yippee

for i in range(N+1):
    dp[i][0] = dp2[i][0] = 1

# note: dp[I][J] is the max product after choosing J elements in the first I of the array 
    
for i in range(1, N+1):
    for j in range(1, min(i, K) + 1):
        dp[i][j] = max(dp[i][j], dp[i-1][j], dp[i-1][j-1] * A[i-1], dp2[i-1][j-1] * A[i-1])
        dp2[i][j] = min(dp2[i][j], dp2[i-1][j], dp2[i-1][j-1] * A[i-1], dp[i-1][j-1] * A[i-1])
        
print(dp[N][K])
