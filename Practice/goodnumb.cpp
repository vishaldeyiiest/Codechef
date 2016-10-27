#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime(int a)
{
	int c = 0;
	for(int i = 1; i <= sqrt(a); i++)
	{
		if(a % i == 0)
			c++;
	}
	if(c == 1)
		return true;
	return false;
}

int sum_of_divisors(int a)
{
	int s = 0;
	for(int i = 2; i <= sqrt(a); i++)
	{
		if(a % i == 0)
		{
			s += i;
			int j = a/i;
            if(j != i)
				s += j;
		}
	}
	return s;
}

int primesum(int m)
{
    int sum = 0;
    for(int i = 1; i <= sqrt(m); i++)
    {
        if(m % i == 0)
        {
            int k=m/i;
            if(prime(i))
                sum++;
            if(k!=i && m%k==0 && prime(k))
            {
                sum++;
            }
        }
    }
    return sum;
}

bool square_free(int n)
{
	bool flag = false;
    for(int j = 2;j <= sqrt(n); j++)
    {
        if(n%(j*j)==0)
            flag = true;
    }
    return flag;
}

int main()
{
	int t;
    int a, b;
    ll ans=0,k;
    ll s[100001] = {0};
    for(int i=5; i<100001; i++)
    {
        if(square_free(i)==0 && prime(primesum(sum_of_divisors(i)))==1)
        {
            ans += sum_of_divisors(i);
        }
        s[i]=ans;
    }
    
	cin >> t;
 
    while(t--)
    {
        cin >> a >> b;
        k=s[b]-s[a-1];
        printf("%lli\n",k);
    }
    return 0;
}
