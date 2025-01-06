#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_NODES 6

struct Vertex {
    int height;
    int excess;
};

void initializeVertex(struct Vertex *v, int height, int excess) {
    v->height = height;
    v->excess = excess;
}

void push(int graph[NUM_NODES][NUM_NODES], struct Vertex vertices[], int u, int v) {
    int flow = (graph[u][v] < vertices[u].excess) ? graph[u][v] : vertices[u].excess;
    graph[u][v] -= flow;
    graph[v][u] += flow;
    vertices[u].excess -= flow;
    vertices[v].excess += flow;
}

void relabel(int graph[NUM_NODES][NUM_NODES], struct Vertex vertices[], int u) {
    int minHeight = INT_MAX;
    for (int v = 0; v < NUM_NODES; ++v) {
        if (graph[u][v] > 0) {
            minHeight = (minHeight < vertices[v].height) ? minHeight : vertices[v].height;
        }
    }
    vertices[u].height = minHeight + 1;
}

void discharge(int graph[NUM_NODES][NUM_NODES], struct Vertex vertices[], int u) {
    while (vertices[u].excess > 0) {
        bool pushed = false;
        for (int v = 0; v < NUM_NODES && vertices[u].excess > 0; ++v) {
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

int pushRelabelMaxFlow(int graph[NUM_NODES][NUM_NODES], int source, int sink) {
    struct Vertex vertices[NUM_NODES];
    for (int i = 0; i < NUM_NODES; ++i) {
        initializeVertex(&vertices[i], 0, 0);
    }
    vertices[source].height = NUM_NODES;
    for (int v = 0; v < NUM_NODES; ++v) {
        if (graph[source][v] > 0) {
            push(graph, vertices, source, v);
        }
    }
    bool done;
    do {
        done = true;
        for (int u = 0; u < NUM_NODES; ++u) {
            if (u != source && u != sink && vertices[u].excess > 0) {
                discharge(graph, vertices, u);
                done = false;
            }
        }
    } while (!done);
    int maxFlow = 0;
    for (int i = 0; i < NUM_NODES; ++i) {
        maxFlow += graph[i][sink];
    }
    return maxFlow;
}

int main() {
    int graph[NUM_NODES][NUM_NODES] = {
        {0, 13, 10, 0, 0, 0},  
        {0, 0, 0, 6, 0, 7},   
        {0, 0, 3, 0, 0, 0},   
        {0, 0, 0, 0, 10, 0},  
        {0, 0, 0, 0, 0, 5},   
        {0, 0, 0, 0, 0, 0}    
    };

    int source = 0;
    int sink = 5;

    int maxFlow = pushRelabelMaxFlow(graph, source, sink);

    printf("The max flow at the Sink node is %d\n", maxFlow);

    return 0;
}