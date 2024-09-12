# include <stdio.h>

int V;

int minkey(int visited[], int key[])
{
    int min = __INT_MAX__;
    int min_index;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==0 && key[i]<min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printmst(int parent[], int graph[][V])
{
    printf("Edge:Weight\n");
    for(int i=1;i<V;i++)
    {
        printf("%d-%d:%d\n",parent[i],i,graph[i][parent[i]]);
    }
}

void prims(int graph[][V])
{
    int parent[V];
    int key[V];
    int visited[V];
    for(int i=0;i<V;i++)
    {
        key[i] = __INT_MAX__;
        parent[i] = 0;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i=0; i<V-1;i++)
    {
        int u = minkey(visited,key);
        visited[u] = 1;
        for(int j=0; j<V;j++)
        {
            if(graph[u][j] && visited[j]==0 && graph[u][j]<key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printmst(parent,graph);
}

int main()
{
    scanf("%d",&V);
    int graph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    prims(graph);
    return 0;
}