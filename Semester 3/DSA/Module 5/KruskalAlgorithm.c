#include <stdio.h>

int V;

int findParent(int parent[], int component) 
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) 
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else 
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int graph[][V]) 
{
    int parent[V];
    int rank[V];
    for (int i = 0; i < V; i++) 
    {
        parent[i] = i;
        rank[i] = 0;
    }
    printf("Edge:Weight\V");
    for(int count=0;count<V-1;count++)
    {
        int min = __INT_MAX__;
        int a = -1;
        int b = -1;
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (findParent(parent, i)!=findParent(parent, j) && graph[i][j] && graph[i][j] <= min) 
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (a != -1 && b != -1) 
        {
            printf("%d-%d:%d\n", a, b, min);
            unionSet(a, b, parent, rank);
        }
    }
}

int main() 
{
    scanf("%d", &V);
    int graph[V][V];
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    kruskalAlgo(graph);
    return 0;
}
