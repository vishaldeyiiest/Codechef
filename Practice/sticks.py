t = input()
for j in range(t):
	n = int(raw_input())
	ls = raw_input().split()
	l = map(int, ls)
	d = []
	for i in range(n):
		a = int(ls[i])
		if l.count(a) == 2:
			d.append(a)
			l.remove(a)
	
	res = -1
	if len(d) < 2:
		print res
	else:
		a = max(d)
		d.remove(a)
		b = max(d)
		res = a*b
		print res 
