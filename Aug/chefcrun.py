def maxsum(A, n, k, l):
	m = k
	r = 0
	t = 0
	while m != l:
		t = max(0,t+A[m])
		r = max(r,t)
		m = (m+1)%n
	return r
	
t = int(raw_input())
for i in range(t):
	n = int(raw_input())
	l = map(int, raw_input().split())
	start, end = map(int, raw_input().split())

	start -= 1
	end -= 1
	cost_f = 0
	cost_b = 0
	i = start
	while i != end:
		cost_f += l[i]
		i = (i+1)%n
	i = (start+n-1)%n
	while i != (end-1+n)%n:
		cost_b += l[i]
		i = (i+n-1)%n
	f = maxsum(l, n, start, end)
	b = maxsum(l, n, end, start)
	cf = cost_f + 2*(cost_b - b)
	cb = cost_b + 2*(cost_f - f)
    
	print min(cf, cb)
