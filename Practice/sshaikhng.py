from collections import defaultdict

def calc(k, x):
	l = []
	l.append(x)
	t = 0
	for i in range(len(l)):
		if t == k:
			break
		for a in graph[l[i]]:
			print a
		l.remove(l[i])
	
	if len(l) == 0:
		print '-1'
	else:
		print len(l)
		l.sort()
		print l
		
n = int(raw_input())
graph = defaultdict(list)
for i in range(n):
	temp = raw_input().split()
	for j in range(n):
		if temp[j] == '1':
			graph[i].append(j)
print graph
m = int(raw_input())
for i in range(m):
	k, x = map(int, raw_input().split())
	x = x - 1
	calc(k, x)
