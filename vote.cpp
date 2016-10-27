#include <bits/stdc++.h>
using namespace std;

void search(int count[], int n, int k)
{
	int c = 0;
	for(int i = 1; i <= n; i++)
	{
		if(count[i] >= k)
			c++;
	}
	cout<<c<<endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int count[101];
		for(int i = 1; i <= n; i++)
			count[i] = 0;
			
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if(x != i)
				count[x]++;
		}
		search(count,n, k);
	}
	return 0;
}
