#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Edge {
    int src, dest;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int findCut(struct Graph* graph) {
    int V = graph->V;
    int E = graph->E;
    struct Edge* edge = graph->edge;
    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = -1;
    int vertices = V;
    while (vertices > 2) {
        int randomEdge = rand() % E;
        int subset1 = find(parent, edge[randomEdge].src);
        int subset2 = find(parent, edge[randomEdge].dest);
        if (subset1 != subset2) {
            Union(parent, subset1, subset2);
            vertices--;
        }
    }
    int cutEdges = 0;
    for (int i = 0; i < E; i++) {
        int subset1 = find(parent, edge[i].src);
        int subset2 = find(parent, edge[i].dest);
        if (subset1 != subset2)
            cutEdges++;
    }
    free(parent);
    return cutEdges;
}

void printContractEdge(struct Edge e) {
    printf("Contracting edge %d-%d\n", e.src, e.dest);
}

int main() {
    srand(time(NULL));
    int V = 4, E = 5;
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[1].src = 1;
    graph->edge[1].dest = 3;
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
    graph->edge[3].src = 0;
    graph->edge[3].dest = 3;
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    printContractEdge(graph->edge[0]);
    printContractEdge(graph->edge[1]);
    int minCut = findCut(graph);
    printf("Cut found by the randomized algorithm is %d\n", minCut);
    free(graph->edge);
    free(graph);
    return 0;
}