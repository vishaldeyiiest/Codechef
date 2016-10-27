dp = [[0 for x in range(250001)] for y in range(250001)] 
def sq(x):
	return x*x

def Pow(n, p):
	if p==0:
		dp[n][p]=1
	if n==0:
		dp[n][p]=0
	if p==1:
		dp[n][p]=n
	if p==2:
		dp[n][p]=n*n
	if dp[n][p]:
		return dp[n][p]
	if p&1:
		dp[n][p]=n*Pow(n,p-1)
	else:
		dp[n][p]=sq(Pow(n,p/2))
	return dp[n][p]
	 
#if __name__ == '__main__':
	
	n = int(raw_input())
	coeff = [1,2,3]
	#coeff = map(int, raw_input().split())
	coeff = reversed(coeff)
	print coeff[0]
	k = int(raw_input())
	
	for i in range(k):
		x = int(raw_input())	
		res = 0
		for j in range(n+1):
			if x < 0:
				temp = Pow(-x, j)
				if j&1:
					temp = -temp
			else:
				temp = Pow(x, j)
			res += coeff[j]*temp
		print (res % mod)
