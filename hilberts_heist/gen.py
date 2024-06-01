from hilbertcurve.hilbertcurve import HilbertCurve
from random import randint as r

N = 100000#r(9000, 10000)
P = 10#r(9, 10)
hc = HilbertCurve(N, 2)

print(N)
print(P)

for i in range(P):

	p1 = r(0, 1<<(2*N))
	p2 = r(0, 1<<(2*N))

	if p2 < p1:
		tmp = p1
		p1 = p2
		p2 = tmp

	D = p2 - p1

	pt1 = hc.point_from_distance(p1)
	pt2 = hc.point_from_distance(p2)

	print(str(pt1[0]) + " " + str(pt1[1]) + " " + str(D))