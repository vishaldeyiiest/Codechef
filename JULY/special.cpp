#include <bits/stdc++.h>
using namespace std;

bool special(long long int n, int k)
{
	//int digits[18];
	int count[10];
	for(int i = 0; i< 10; i++)
		count[i] = 0;
	long long int x = n;
	
	while(n > 0)
	{
		count[n%10]++;
		n /= 10;
	}
	int c = 0;
	for(int j = 1; j <= 9; j++)
	{
		//cout<<count[j]<< " ";
		if(count[j] >= 1 && x % j == 0 )
			c++;
	}
	if(c >= k)
		return true;
	return false;	
}
	
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		long long int l, r;
		int k;
		long int count = 0;
		cin >> l;
		cin >> r;
		cin >> k;
		//cout<<l<<" "<<r<<" "<<k<<endl;
		while(l <= r)
		{
			if(special(l, k))
				count++;
			l++;
		}
		cout << count << endl;
	}
	return 0;
}
