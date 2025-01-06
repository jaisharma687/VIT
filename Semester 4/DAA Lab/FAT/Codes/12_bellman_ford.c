#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int src;
    int dest;
    int weight;
}Node;

typedef struct {
    int V;
    int E;
    Node *edge;
}graph;

graph *createGraph(int v, int e) {
    graph *temp = (graph *)malloc(sizeof(graph));
    temp -> E = e;
    temp -> V = v;
    temp -> edge = (Node *)malloc(e * sizeof(Node ));
    return temp;
}

void bellmanFord(graph *head, int distance[], char vertex[]){
    distance[0] = 0;
    for (int i = 1; i < head -> V; i ++) {
        for (int j = 0; j < head -> E; j ++) {
            int u = head -> edge[j].src;
            int v = head -> edge[j].dest;
            int weight = head -> edge[j].weight;
            if ((distance[u] != INT_MAX) && (distance[u] + weight < distance[v])) {
                distance[v] = distance[u] + weight;
            }
        }
    }
    for (int i = 1; i < head->V; i++){
        for (int j = 0; j < head->E; j++){
            int u = head->edge[j].src;
            int v = head->edge[j].dest;
            int weight = head->edge[j].weight;
            if ((distance[u] != INT_MAX) && (distance[u] + weight < distance[v])){
                printf("Negative Cycle\n");
            }
        }
    }
    for (int i = 0; i < head -> V; i ++) {
        printf("%c-%d\n",vertex[i], distance[i]);
    }
}

int main() {
    char vertex[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int distance[6];
    for(int i = 0; i < 6; i ++) { 
        distance[i] = INT_MAX;
    }
    graph *bellgraph = createGraph(6, 9);
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
    bellmanFord(bellgraph, distance, vertex);
    return 0;
}