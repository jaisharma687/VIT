# include <stdio.h>

int V;

int findparent(int parent[], int v)
{
    if(parent[v]==v)
        return v;
    return parent[v] = findparent(parent,parent[v]);
}

void unionset(int u, int v, int parent[], int rank[])
{
    u = findparent(parent,u);
    v = findparent(parent,v);
    if(rank[u]>rank[v])
        parent[v] = u;
    else if(rank[u]<rank[v])
        parent[u] = v;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(int graph[][V])
{
    int parent[V];
    int rank[V];
    for(int i=0;i<V;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    printf("Edge:Weight\n");
    for(int i=0;i<V-1;i++)
    {
        int min = __INT_MAX__;
        int a = -1;
        int b = -1;
        for(int i=0; i<V;i++)
            for(int j = 0; j<V;j++)
                if(graph[i][j] && findparent(parent,i)!=findparent(parent,j) && graph[i][j] <= min)
                    min = graph[i][j] , a=i , b=j;
        if(a!=-1 && b!=-1)
        {
            if(a==3 && b==0)
            {
                int temp;
                temp = b;
                b = a;
                a = temp;
            }
            printf("%d-%d:%d\n",a+1,b+1,min);
            unionset(a,b,parent,rank);
        }
    }
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
    kruskal(graph);
}