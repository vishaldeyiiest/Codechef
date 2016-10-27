n, x, y = map(int, raw_input().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())
l = []
ans = 0
for i in range(n):
	l.append(a[i] - b[i])
l.sort(reverse = True)
p = max(0, n-y)
q = min(n, x)
r = sum(b)
for i in range(p):
	r += l[i]
ans = r
for i in range(p, q):
	r += l[i]
	ans += max(ans, r)
print ans
			
