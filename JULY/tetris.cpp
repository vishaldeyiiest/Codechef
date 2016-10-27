#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[10000], b[10000];
		for(int i = 0; i < n; i++)
			cin >> b[i];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		if(n == 1)
		{
			cout << a[n-1] + b[n-1] << endl;
			break;
		}
		int c[70000];
		for(int i = 0; i < n; i++)
			c[i] = b[i];
		for(int i = n; ;i++)
		{
			c[i] = c[i
