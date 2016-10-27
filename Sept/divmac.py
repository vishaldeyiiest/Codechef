divisor = []
li = []
def prime(n):
	c = 0
	for i in range(1,n):
		if n%i == 0:
			c += 1
	if c == 1:
		return 1
	return 0

def leastprimedivisor(n):
	x = []
	for i in range(1, n+1):
		if n%i == 0 and prime(i) == 1:
			#print i
			x.append(i)
	if len(x) == 0:
		return 1
	return min(x)	
	

def update(l, r):
	for i in range(l-1, r):
		li[i] = li[i]/divisor[i]
		#print li[i]
		divisor[i] = leastprimedivisor(li[i]) 

def get(l, r):
	result = max(divisor[l-1:r])
	return result 

t = int(raw_input())
for i in range(t):
	n, m = raw_input().split()
	n = int(n)
	m = int(m)
	li = map(int, raw_input().split())
	for i in li:
		divisor.append(leastprimedivisor(i))
	for i in range(m):
		q, l, r = raw_input().split()
		q = int(q)
		l = int(l)
		r = int(r)
		#l -= 1
		#r -= 1
		if q == 0:
			update(l, r)
		else:
			print get(l, r)
