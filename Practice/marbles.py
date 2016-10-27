def binomial(n, k):
	ans = 1
	k = min(k, n-k)
	for i in range(k):
		ans *= (n-i)
		ans = ans/(i+1)
	return ans
	
t = int(raw_input())

for i in range(t):
	n, k = map(int, raw_input().split())
	n -= 1
	k -= 1
	print binomial(n, k)
