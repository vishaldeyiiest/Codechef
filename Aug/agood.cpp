#include <bits/stdc++.h>
#define n 10000
#include <algorithm>
using namespace std;
int f(long long int a, long long int b)
{
	if(((a&b) == a )||((a&b) == b))
		return 1;
	else
		return 0;
}
long long int max(long long int a, long long int b)
{
	return (a>b)?a:b;
}

int main()
{
	int t;
	long long int a[n];
	cin >> t;
	for(int i = 0; i < t; i++)
		cin >> a[i];
	long long int res = 0;
	for(int i = 0; i < t; i++)
	{
		for(int j = i+1; j < t; j++)
		{
			res += max(a[i], a[j])*f(a[i], a[j]);
			cout << res<< " ";
		}
	}
	cout<<res<<endl;
}
