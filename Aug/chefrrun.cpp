#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{	
		int n;
		int visited[100001];
		int a[100001];
		cin >> n;
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			visited[i] = 0;
			a[i] = a[i] % n;
		}
		int si = 1;
		for(int i = 0; i < n; i++)
		{
			//if(!visited[i])
			{
				int s = i;
				int temp = si;
				for(; !visited[s]; s = (s+a[s]+1)%n)
				{
					visited[s] = si++;
				}
				if(visited[s] >= temp)
					count += si - visited[s];
				si++;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}
