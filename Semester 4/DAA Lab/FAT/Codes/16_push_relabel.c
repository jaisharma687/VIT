#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 7

typedef struct {
    int height;
    int excess;
} Vertex;

void initializeVertex(Vertex *v, int height, int excess) {
    v->height = height;
    v->excess = excess;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void push(int graph[V][V], Vertex vertices[], int u, int v) {
    int flow = min(graph[u][v], vertices[u].excess);
    graph[u][v] -= flow;
    graph[v][u] += flow;
    vertices[u].excess -= flow;
    vertices[v].excess += flow;
}

void relabel(int graph[V][V], Vertex vertices[], int u) {
    int minHeight = INT_MAX;
    for (int v = 0; v < V; ++v) {
        if (graph[u][v] > 0) {
            minHeight = min(minHeight, vertices[v].height);
        }
    }
    vertices[u].height = minHeight + 1;
}

void discharge(int graph[V][V], Vertex vertices[], int u) {
    while (vertices[u].excess > 0) {
        bool pushed = false;
        for (int v = 0; v < V && vertices[u].excess > 0; ++v) {
            if (graph[u][v] > 0 && vertices[u].height == vertices[v].height + 1) {
                push(graph, vertices, u, v);
                pushed = true;
            }
        }
        if (!pushed) {
            relabel(graph, vertices, u);
        }
    }
}

int pushRelabelMaxFlow(int graph[V][V], int source, int sink) {
    Vertex vertices[V];
    for (int i = 0; i < V; ++i) {
        initializeVertex(&vertices[i], 0, 0);
    }
    vertices[source].height = V;
    for (int v = 0; v < V; ++v) {
        if (graph[source][v] > 0) {
            push(graph, vertices, source, v);
        }
    }
    bool done;
    do {
        done = true;
        for (int u = 0; u < V; ++u) {
            if (u != source && u != sink && vertices[u].excess > 0) {
                discharge(graph, vertices, u);
                done = false;
            }
        }
    } while (!done);
    int maxFlow = 0;
    for (int i = 0; i < V; ++i) {
        maxFlow += graph[i][sink];
    }
    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 5, 10, 0, 4, 0, 0},
        {0, 0, 0, 1, 0, 0, 3},
        {0, 0, 0, 7, 3, 7, 0},
        {0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int source = 0;
    int sink = 6;
    int maxFlow = pushRelabelMaxFlow(graph, source, sink);
    printf("The max flow at the Sink node is %d\n", maxFlow);
    return 0;
}
