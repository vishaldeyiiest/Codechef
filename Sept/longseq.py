t = int(raw_input())
for i in range(t):
	n = str(raw_input())
	l = []
	for digit in n:
		l.append(digit)
	
	if l.count('0') == 1 or l.count('1') == 1:
		print "Yes"
	else:
		print "No" 
