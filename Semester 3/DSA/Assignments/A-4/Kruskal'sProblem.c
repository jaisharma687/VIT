#include <stdio.h>
#include <stdlib.h>

void makeSet(int parent[], int rank[], int n) 
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) 
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n) 
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int n, int graph[][n]) 
{
    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);
    int edges = 0;
    printf("Edge:Weight\n");
    while (edges < n - 1) 
    {
        int min =INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (findParent(parent, i) != findParent(parent, j) && graph[i][j] && graph[i][j] < min) {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if (a != -1 && b != -1) 
        {
            printf("%d-%d:%d\n", a, b, min);
            unionSet(a, b, parent, rank, n);
            edges++;
        }
    }

}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    kruskalAlgo(V, graph);
    return 0;
}
