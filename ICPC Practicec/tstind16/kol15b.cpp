#include <bits/stdc++.h>
using namespace std;

long int min(int a, long int b)
{
	return (a<b) ? a : b;
}
 
int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m;
	    cin >> n >> m;
	    long int north[1001][1001], south[1001][1001], east[1001][1001], west[1001][1001];
	    long int arr[1001][1001];
	    long int ans = LONG_MAX;
	    for(int i = 1;i <= n; i++)
	    {
	        for(int j = 1;j <= m; j++)
	        {
	            cin >> arr[i][j];
	            //east[i][j] = north[i][j] = south[i][j] = west[i][j] = 0;
	        }
	    }
	    for(int i = 1; i <= n; i++)
			east[i][1] = arr[i][1];
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 2; j <= m; j++)
	        {
	            east[i][j] = min(arr[i][j], east[i][j-1] + arr[i][j]);
	        }
	    }
	    for(int i = 1;i <= m; i++)
			north[1][i] = arr[1][i];
	    for(int i = 2;i <= n; i++)
	    {
	        for(int j = 1;j <= m; j++)
	        {
	            north[i][j] = min(arr[i][j], arr[i][j] + north[i-1][j]);
	        }
	    }
	    for(int i = 1; i <= m; i++)
			south[n][i] = arr[n][i];
	    for(int i = n-1; i >= 1; i--)
	    {
	        for(int j = 1; j <= m; j++)
	        {
	            south[i][j] = min(arr[i][j], arr[i][j] + south[i+1][j]);
	        }
	    }
	    for(int i = 1; i <= n; i++)
			west[i][m] = arr[i][m];
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = m-1; j >= 1; j--)
	        {
	            west[i][j] = min(arr[i][j], arr[i][j]+west[i][j+1]);
	        }
	    }
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= m; j++)
	        {
	            ans=min(ans, north[i][j] + south[i][j] + west[i][j] + east[i][j] - 3*arr[i][j]);
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
