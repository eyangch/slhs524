N = int(input())
A = [*map(int, input().split())]
idx = 1
while idx < N and A[idx] == A[0]:
    idx += 1
    
print(idx + 1)