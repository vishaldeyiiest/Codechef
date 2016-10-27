def solve(l, n, m):
	maxsum = sum(x[1] for x in l)
	minsum = sum(x[0] for x in l)
	if maxsum < m*n:
		return -1
	if minsum >= m*n:
		return 0
	l.sort(key = lambda x: x[2], reverse = True)
	hr = 0
	c = [0]*n
	i = 0
	while minsum < m*n:
		if l[i][0] + l[i][2]*(c[i]+1) <= l[i][1]:
			c[i] = c[i]+1
			minsum += l[i][2]
			hr += 1
		else:
			i = i+1
	return hr
	
n, m = map(int, raw_input().split())
l = []
for i in range(n):
	l.append(tuple(map(int, raw_input().split())))
print solve(l, n, m)	
