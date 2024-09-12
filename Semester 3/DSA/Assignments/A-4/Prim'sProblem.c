#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int V;

int minKey(int key[], bool mstSet[], int V)
{
	int min = INT_MAX;
    int min_index;
	for (int v = 0; v < V; v++)
	{
        if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
    }
	return min_index;
}

void printMST(int parent[], int graph[][V] , int V)
{
	printf("Edge:Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d-%d:%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[][V],int V)
{
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V - 1; count++) 
    {
		int u = minKey(key, mstSet,V);
		mstSet[u] = true;
		for (int v = 0; v < V; v++)
		{	
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
        }
	}
	printMST(parent, graph,V);
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
	// int graph[V][V] = { {0 ,4 ,0 ,0 ,0 ,0 ,7 ,0 ,0},
    //                     {4 ,0 ,9 ,0 ,0 ,0 ,11 ,20 ,0},
    //                     {0 ,9 ,0 ,6 ,2 ,0 ,0 ,0 ,0},
    //                     {0 ,0 ,6 ,0 ,10 ,5 ,0 ,0 ,0},
    //                     {0 ,0 ,2 ,10 ,0 ,15 ,0 ,1 ,5},
    //                     {0 ,0 ,0 ,5 ,15 ,0 ,0 ,0 ,12},
    //                     {7 ,11 ,0 ,0 ,0 ,0 ,0 ,1 ,0},
    //                     {0 ,20 ,0 ,0 ,1 ,0 ,1 ,0 ,3},
    //                     {0 ,0 ,0 ,0 ,5 ,12 ,0 ,3 ,0}};
	primMST(graph,V);
	return 0;
}
