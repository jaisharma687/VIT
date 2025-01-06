#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int V;

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}

void printSolution(int dist[])
{
	for (int i = 0; i < V; i++)
		printf("Distance of vertex %d:%d\n", i+1, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src-1] = 0;
	for (int count = 0; count < V - 1; count++) 
    {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist);
}

int main()
{
	scanf("%d",&V);
    int graph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            int ele;
            scanf("%d",&ele);
            graph[i][j] = ele;
        }
    }
	// int graph[5][5] = { { 0, 0, 6, 3, 0},
	// 					{ 3, 0, 0, 0, 0},
	// 					{ 0, 0, 0, 2, 0},
	// 					{ 0, 1, 1, 0, 0},
	// 					{ 0, 4, 0, 2, 0 } };
    printf("From source vertex 5\n");
	dijkstra(graph, 5);
	return 0;
}