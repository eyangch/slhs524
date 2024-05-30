F, S = map(str, input().split())
F, S = F.count('#'), S.count('#')
print(max(F, S), F * S)