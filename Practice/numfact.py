t = int(raw_input())
for i in range(t):
	n = int(raw_input())
	l = map(int, raw_input().split())
	di = dict()
	for no in l:
		j = 2
		while j*j <= no:
			while no%j == 0:
				no /= j
				di[j] = di.get(j,0) + 1
			j += 1
		if no > 1:
			di[no] = di.get(no,0) + 1
	res = 1
	for k,v in di.items():
		res *= (v+1)
	print res
