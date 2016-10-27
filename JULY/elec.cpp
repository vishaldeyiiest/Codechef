#include <bits/stdc++.h>
using namespace std;

unsigned int min_dist(int a[], int x[], int i, int n)
{
	int min = INT_MAX;
	for(int j = 0; j < n; j++)
	{
		if(j != i && a[j] == 1 && abs(x[j] - x[i]) <= min)
			min = abs(x[j] - x[i]);
	}
	return min;
}
int flag = 0;		
int update(int b[], int a[], int x[], int n)
{
	flag = 0;
	int min = INT_MAX, k = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
		{
			b[i] = min_dist(a, x, i, n);
		}
		if(b[i] != 0)
			flag = 1;
		if(b[i] <= min && b[i] != 0)
			min = b[i], k = i;
		//cout << b[i]<<" ";
	}
	return k;
}
		
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[100000];
		int x[100000];
		
		string s;
		cin >> s;
		for(unsigned int i = 0; i < strlen(s.c_str()); i++)
			a[i] = s[i] - '0';
		for(int i = 0; i < n; i++)
		{
			cin >> x[i];
			//cout << x[i];
		}
		int b[100000];
		//b = new int(n);
		memset(b, 0, n);
		int min = update(b, a, x, n);
		int ans = 0;
		while(flag == 1)
		{
			ans += b[min];
			b[min] = 0;
			a[min] = 1;
			min = update(b, a, x, n);
		}
		cout<<ans<<endl;
			
	}
	return 0;
}
