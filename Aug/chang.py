def update(h, m, n):
	for i in range(n):
		h[i] = h[i] + m[i];
	return h
	
t = int(raw_input())
n = int(raw_input())
h = []
m = []
for i in range(n):
	a, b = map(int, raw_input().split())
	h.append(a)
	m.append(b)
	
for i in range(1,n-2):
	if h[i-1] > h[i] and h[i] < h[i+1] and h[i+1] > h[i+2]:
		break
	elif h[i-1] < h[i] and h[i] > h[i+1] and h[i+1] < h[i+2]:
		break
	
