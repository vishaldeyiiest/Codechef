#include <bits/stdc++.h>
#define MAX 1000000
#define MOD 1000000007
using namespace std;

long long power(int x, long long y, long long p)
{
	int res = 1;      
    x = x % p; 
    while (y > 0)
    {
		if (y & 1)
            res = (res*x) % p;
        y = y >> 1;
        x = (x*x) % p;  
    }
    return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	int F[MAX] = {0};
	int max_ele = INT_MIN;
	for(int i = 1; i <= n; i++)
	{
		cin >> F[i];
		if(F[i] > max_ele)
			max_ele = F[i];
	}
	long long int to_add, to_subtract, subsets, ans;
	int F2[MAX];
	for(int i= max_ele ; i >= 1;--i)
    {
		to_add=F[i];
		to_subtract = 0 ;
        for(int j=2 ;j*i <= max_ele;++j)
        {
			to_add+=F[j*i];
            to_subtract+=F2[j*i];
            to_subtract>=(MOD-1)?(to_subtract%=(MOD-1)):0;
        }
        subsets = (((power(2 , to_add , MOD-1) ) - 1) - to_subtract)%(MOD-1) ;

        if(subsets<0)
			subsets = (subsets%(MOD-1) +MOD-1)%(MOD-1);

       ans  = ans * power(i , subsets , MOD);
       F2[i]= subsets;
       ans %=MOD;
   }
	}
}
