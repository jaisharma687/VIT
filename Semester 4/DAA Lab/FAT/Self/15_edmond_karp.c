#include <stdio.h>
#include <limits.h>

#define V 6

typedef struct{
    int adjMatrix[V][V];
    char* vertexNames[V];
}Graph;

void initialize_graph(Graph *g, char * vertex[]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            g->adjMatrix[i][j] = 0;
        }
    }
    for(int i=0;i<V;i++){
        g->vertexNames[i] = vertex[i];
    }
}

void addEdge(Graph *g, int src, int dest, int cap){
    g->adjMatrix[src][dest] = cap;
}

int bfs(Graph *g, int s, int t, int parent[]){
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }
    int queue[V],front=0,rear=0;
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;
    while(front < rear){
        int u = queue[front++];
        for(int v=0;v<V;v++){
            if(!visited[v] && g->adjMatrix[u][v] > 0){
                if(v==t){
                    parent[v] = u;
                    return 1;
                }
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return 0;
}

int edmondKarp(Graph *g, int source, int sink){
    int u,v,max_flow=0,parent[V];
    while(bfs(g,source,sink,parent)){
        int path_flow = INT_MAX;
        for(v=sink;v!=source;v=parent[v]){
            u = parent[v];
            path_flow = path_flow < g->adjMatrix[u][v] ? path_flow : g->adjMatrix[u][v];
        }
        for(v=sink;v!=source;v=parent[v]){
            u = parent[v];
            g->adjMatrix[u][v] -= path_flow;
            g->adjMatrix[v][u] += path_flow;
        }
        max_flow += path_flow;
        int path[V],pathSize=0;
        for(v=sink;v!=source;v=parent[v]){
            path[pathSize++] = u;
        }
        printf("Path: s -> ");
        for(int i=pathSize-1;i>=0;i--){
            printf("%s ",g->vertexNames[path[i]]);
            if (i>0) printf("-> ");
        }
        printf(", Flow: %d\n",path_flow);
    }
    return max_flow;
}

int main(){
    Graph g;
    char* vertexNames[] = {"s", "A", "B", "C", "D", "t"};
    initialize_graph(&g, vertexNames);
    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 3, 10);
    addEdge(&g, 1, 2, 4);
    addEdge(&g, 1, 3, 2);
    addEdge(&g, 1, 4, 8);
    addEdge(&g, 2, 5, 10);
    addEdge(&g, 3, 4, 9);
    addEdge(&g, 4, 2, 6);
    addEdge(&g, 4, 5, 10);
    printf("The maximum possible flow is %d\n", edmondKarp(&g,0, 5));
    return 0;
}