#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 1000

int n, e;
int particion[MAX], visited[MAX];
vector< int > adjacencyMatrix[MAX];

bool bfs(int begin)
{
    int origin, destination;
    queue<int> queueVertex;
    queueVertex.push(begin);
    particion[begin] = 1; 
    visited[begin] = 1; 

    while(!queueVertex.empty())
    {
        origin = queueVertex.front(); queueVertex.pop();
        for(unsigned int i=0; i < adjacencyMatrix[origin].size(); i++)
        {
            destination = adjacencyMatrix[origin][i];
            if(particion[origin] == particion[destination])
            {
                return false;
            }
            if(visited[destination] == 0)
            {
                visited[destination] = 1;
                particion[destination] = 3 - particion[origin]; // alter 1 and 2 subsets
                queueVertex.push(destination);
            }
        }
    }
    return true;
}

bool is_bipartite()
{
    for(int i=0; i< n; i++)
    {
       if (visited[i] == 0 && !bfs(i)) {
           return false;
       }
    } 
    return true;
}
void complement()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i!=j && adjacencyMatrix[i][j] == 0)
				adjacencyMatrix[i][j] = 1;
			else
				adjacencyMatrix[i][j] = 0;
		}
	}
}
int main()
{
    //freopen("tarea2.in", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
		int nodeOrigin, nodeDestination;
		cin >> n >> e;
		for(int i=0; i< e; i++)
		{
			scanf("%d %d", &nodeOrigin, &nodeDestination);
			nodeOrigin--, nodeDestination--;
			adjacencyMatrix[nodeOrigin].push_back(nodeDestination);
			adjacencyMatrix[nodeDestination].push_back(nodeOrigin);
		}
		//complement();
		if(is_bipartite())
			cout << "YES" << endl;
		else
			cout << "NO" <<endl;

    }
    

    return 0;
}
