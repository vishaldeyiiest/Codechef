n = int(raw_input())
l = map(int, raw_input().split())
dic = {}
ans = 0
for i in range(n):
	for j in range(i+1, n):
		k = l[i] + l[j]
		dic[k] += 1
		if dic[k] > ans:
			ans = dic[k]
print 2*ans
