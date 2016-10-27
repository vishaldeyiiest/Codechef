t = int(raw_input())
for i in range(t):
	n, name = raw_input().split()
	n = int(n)
	name = str(name)
	l = map(int, raw_input().split())
	if sum(l)%2 == 0:
		if name == 'Dee':
			print 'Dum'
		else:
			print 'Dee'
	else:
		if name == 'Dum':
			print 'Dee'
		else:
			print 'Dum'
		
