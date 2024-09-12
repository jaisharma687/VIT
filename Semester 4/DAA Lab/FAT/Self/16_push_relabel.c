#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

typedef struct{
    int height;
    int excess;
}Vertex;

void initializeVertex(Vertex *vert,int h, int e){
    vert->height = h;
    vert->excess = e;
}

int min(int a, int b){
    return a<b ? a: b;
}

void push(int graph[V][V],Vertex vert[],int u,int v){
    int flow = min(graph[u][v],vert[u].excess);
    graph[u][v] -= flow;
    graph[v][u] += flow;
    vert[u].excess -= flow;
    vert[v].excess += flow;
}

void relabel(int graph[V][V], Vertex vert[],int u){
    int minHeight = INT_MAX;
    for(int v=0;v<V;v++){
        if(graph[u][v] > 0){
            minHeight = min(minHeight,vert[v].height);
        }
    }
    vert[u].height = minHeight + 1;
}

void discharge(int graph[V][V], Vertex vert[], int u){
    while(vert[u].excess > 0){
        bool pushed = false;
        for(int v=0;v<V && vert[u].excess >0 ;v++){
            if(graph[u][v] > 0 && vert[u].height == vert[v].height + 1){
                push(graph,vert,u,v);
                pushed = true;
            }
        }
        if(!pushed){
            relabel(graph,vert,u);
        }
    }
}

int pushRelabel(int graph[V][V],int source, int sink){
    Vertex vert[V];
    for(int i=0;i<V;i++){
        initializeVertex(&vert[i],0,0);
    }
    vert[source].height = V;
    for(int v=0;v<V;v++){
        if(graph[source][v] >0){
            push(graph,vert,source,v);
        }
    }
    bool done;
    do{
        done = true;
        for(int u=0;u<V;u++){
            if(u!=source && u!=sink && vert[u].excess > 0){
                discharge(graph,vert,u);
                done = false;
            }
        }
    }while(!done);
    int max_flow = 0;
    for(int i=0;i<V;i++){
        max_flow += graph[i][sink];
    }
    return max_flow;
}

int main(){
    int graph[V][V] = {
        {0, 13, 10, 0, 0, 0},
        {0, 0, 0, 6, 0, 7},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 10, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}
    };
    int max_flow = pushRelabel(graph,0,5);
    printf("%d",max_flow);
    return 0;
}