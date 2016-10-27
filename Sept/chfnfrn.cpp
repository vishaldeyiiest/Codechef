#include <bits/stdc++.h>
using namespace std;
int g[1000][1000];
bool isBipartite(int V)
{
	int src = 0;
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;

    queue <int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
		for (int v = 0; v < V; ++v)
        {
            if (g[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (g[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}
void complement(int V)
{
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(i!=j && g[i][j] == 0)
				g[i][j] = 1;
			else
				g[i][j] = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
    int n, e;
    scanf("%d%d", &n, &e);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
			g[i][j] = 0;
		}
	}
    while(e--)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
       g[v1-1][v2-1] = g[v2-1][v1-1] = 1;
    }
 
    //printf("\n\n\n");
	complement(n);
    printf("%s\n", isBipartite(n)? "YES" : "NO");
	}
 
    return 0;
}
