import math
t = int(raw_input())
for i in range(t):
	a = str(raw_input())
	a = list(a)
	f = 1
	l = len(a)
	#print l 
	for i in range(l):
		if a[i] == a[l-i-1]:
			if a[i] == '.':
				a[i] = a[l-i-1] = 'a'
		else:
			if a[i] != '.' and a[l-1-i] != '.':
				f = 0
				break
			elif a[i] == '.':
				a[i] = a[l-i-1]
	if f == 0:
		print '-1'
	else:
		print ''.join(a)
