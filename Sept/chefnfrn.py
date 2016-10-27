t = int(raw_input())
for i in range(t):
	n, m = raw_input().split()
	n = int(n)
	m = int(m)
	l = []
	for i in range(n):
		l.append(0)
	for i in range(m):
		a, b = raw_input().split()
		a = int(a)
		b = int(b)
		#print a, b
		l[a-1] += 1
		l[b-1] += 1
	m = max(l)
	for i in range(len(l)):
		if l[i] == m:
			l[i] -= 1
	m = max(l)
	if l.count(m) == n:
		print "YES"
	else:
		print "NO"
