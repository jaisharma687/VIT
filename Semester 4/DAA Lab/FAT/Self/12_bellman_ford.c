#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int src;
    int dest;
    int weight;
}Node;

typedef struct{
    int V;
    int E;
    Node *edge;
}Graph;

Graph *createGraph(int v, int e){
    Graph *temp = (Graph *)malloc(sizeof(Graph));
    temp->V = v;
    temp->E = e;
    temp->edge = (Node *)malloc(e * sizeof(Node));
    return temp;
}

void bellmanFord(Graph * map,int* dist,char* vertex){
    dist[0] = 0;
    for(int i=1;i<map->V;i++){
        for(int j=0;j<map->E;j++){
            int u = map->edge[j].src;
            int v = map->edge[j].dest;
            int weight = map->edge[j].weight;
            if((dist[u] != INT_MAX) && (dist[u] + weight < dist[v])){
                dist[v] = dist[u] + weight;
            }
        }
    }
    for(int i=1;i<map->V;i++){
        for(int j=0;j<map->E;j++){
            int u = map->edge[j].src;
            int v = map->edge[j].dest;
            int weight = map->edge[j].weight;
            if((dist[u] != INT_MAX) && (dist[u] + weight < dist[v])){
                printf("Negative Cycle");
            }
        }
    }
    for(int i=0;i<map->V;i++){
        printf("%c-%d\n",vertex[i],dist[i]);
    }
}

int main(){
    char vertex[] = {'A','B','C','D','E','F'};
    int V=6;
    int E=9;
    int distance[V];
    for(int i=0;i<V;i++){
        distance[i] = INT_MAX;
    }
    Graph *bellgraph = createGraph(V,E);
    bellgraph -> edge[0].src = 0;
    bellgraph->edge[0].dest = 1;
    bellgraph->edge[0].weight = 6;
    bellgraph->edge[1].src = 0;
    bellgraph->edge[1].dest = 2;
    bellgraph->edge[1].weight = 4;
    bellgraph->edge[2].src = 0;
    bellgraph->edge[2].dest = 3;
    bellgraph->edge[2].weight = 5;
    bellgraph->edge[3].src = 1;
    bellgraph->edge[3].dest = 4;
    bellgraph->edge[3].weight = -1;
    bellgraph->edge[4].src = 2;
    bellgraph->edge[4].dest = 1;
    bellgraph->edge[4].weight = -2;
    bellgraph->edge[5].src = 2;
    bellgraph->edge[5].dest = 4;
    bellgraph->edge[5].weight = 3;
    bellgraph->edge[6].src = 3;
    bellgraph->edge[6].dest = 5;
    bellgraph->edge[6].weight = -1;
    bellgraph->edge[7].src = 3;
    bellgraph->edge[7].dest = 2;
    bellgraph->edge[7].weight = -2;
    bellgraph->edge[8].src = 4;
    bellgraph->edge[8].dest = 5;
    bellgraph->edge[8].weight = 3;
    bellmanFord(bellgraph,distance,vertex);
    return 0;
}