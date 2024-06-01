from random import randint as r

for i in range(5):
	if i == 0:
		print(r(1, 9), end="")
	else:
		print(r(0, 9), end="")
print()