from collections import Counter
def calc(d):
	s = 0
	while not all(x==0 for x in d.values()) :
		x = 0
		for i in d:
			if d[i] > 0:
				x += 1
				d[i] -= 1
		if x == 6:
			s += 4
		elif x == 5:
			s += 2
		elif x == 4:
			s += 1
	return s
	
t = int(raw_input())
for i in range(t):	
	m = int(raw_input())
	score = []
	maxscore = 0
	for i in range(m):
		n = map(int, raw_input().split())
		l = n[1:]
		mydict = {}
		for i in l:
			if i in mydict: mydict[i] += 1
			else: mydict[i] = 1
		score.append(calc(mydict) + len(l))
	flag = []
	for i in range(len(score)):
		if score[i] >= max(score):
			flag.append(i)
	if len(flag) == 1:
		if flag[0] == 0:
			print 'chef'
		else:
			print flag[0]+1
	else:
		print 'tie'
