# include <stdio.h>

int V;

int mindist(int dist[], int visited[])
{
    int min = __INT_MAX__;
    int min_index;
    for(int i=0; i<V;i++)
    {
        if(visited[i]== 0 && dist[i]<=min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printdist(int dist[],int src)
{
    for(int i=0;i<V;i++)
    {
        printf("Distance of vertex %d from %d : %d\n",i+1,src,dist[i]);
    }
}

void dijkstra(int graph[][V], int src)
{
    int visited[V];
    int dist[V];
    for(int i=0; i<V;i++)
    {
        dist[i] = __INT_MAX__;
        visited[i] = 0;
    }
    dist[src-1] = 0;
    for(int i=0; i<V-1;i++)
    {
        int u = mindist(dist,visited);
        visited[u] = 1;
        for(int j=0;j<V;j++)
        {
            if(graph[u][j] && visited[j]==0 && dist[u]!=__INT_MAX__ && dist[u]+graph[u][j] < dist[j])
            {
                dist[j] = dist[u]+graph[u][j];
            }
        }
    }
    printdist(dist,src);
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
    dijkstra(graph,5);
    return 0;
}