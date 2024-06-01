from random import randint as r

T = 1

print(T)

for z in range(T):
	for i in range(10):
		if i == 0:
			print(r(1, 9), end="")
		else:
			print(r(0, 9), end="")
	print()