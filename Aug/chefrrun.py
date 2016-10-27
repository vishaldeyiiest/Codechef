def check(l, x, n):
	i = x
	for each in range(n):
		i = (i + l[i] + 1)%n
		if i == x:
			return 1
	return 0
	
t = int(raw_input())
for i in range(t):
	n = int(raw_input())
	l = map(int, raw_input().split())
	count = 0
	for i in range(n):
		if check(l, i, n) == 1:
			count += 1
	print count
