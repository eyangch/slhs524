#!/usr/bin/python3

N, M, K = map(int, input().split())
ans = 0
freq = [0 for _ in range(N + M + 1)]
for i in range(N+1):
    for j in range(M+1):
        freq[i + j] += 1
        
for i in range(N + M + 1):
    avg = K // freq[i]
    # this should be the average number of people in each cell of this diagonal
    # but there could be extra people
    left = K % freq[i]
    ans += avg**2 * (freq[i] - left)
    ans += (avg+1)**2 * left
    
print(ans)