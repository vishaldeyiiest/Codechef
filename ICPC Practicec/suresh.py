t = int(raw_input())
for i in range(t):
	res = 0.0
	n = int(raw_input())
	for i in range(n):
		l = raw_input().split()
		t = float(l[0])
		p = float(l[1])
		res = (res+t)/p
	print "%.8f" % res
