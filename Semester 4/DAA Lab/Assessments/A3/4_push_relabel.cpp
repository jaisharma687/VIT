#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int flow, capacity;
    int u, v;
    Edge(int flow, int capacity, int u, int v) {
        this->flow = flow;
        this->capacity = capacity;
        this->u = u;
        this->v = v;
    }
};

struct Vertex {
    int h, e_flow;
    Vertex(int h, int e_flow) {
        this->h = h;
        this->e_flow = e_flow;
    }
};

class Graph {
    int V;
    vector<Vertex> ver;
    vector<Edge> edge;
    bool push(int u);
    void relabel(int u);
    void preflow(int s);

    // Helper methods
    int overFlowVertex(vector<Vertex>& ver);
    void updateReverseEdgeFlow(int i, int flow);

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int getMaxFlow(int s, int t);
};

Graph::Graph(int V) {
    this->V = V;
    for (int i = 0; i < V; i++)
        ver.push_back(Vertex(0, 0));
}

void Graph::addEdge(int u, int v, int capacity) {
    edge.push_back(Edge(0, capacity, u, v));
}

void Graph::preflow(int s) {
    ver[s].h = ver.size();
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].u == s) {
            edge[i].flow = edge[i].capacity;
            ver[edge[i].v].e_flow += edge[i].flow;
            edge.push_back(Edge(-edge[i].flow, 0, edge[i].v, s));
        }
    }
}

int Graph::overFlowVertex(vector<Vertex>& ver) {
    for (int i = 1; i < ver.size() - 1; i++)
        if (ver[i].e_flow > 0)
            return i;
    return -1;
}

void Graph::updateReverseEdgeFlow(int i, int flow) {
    int u = edge[i].v, v = edge[i].u;
    for (int j = 0; j < edge.size(); j++) {
        if (edge[j].v == v && edge[j].u == u) {
            edge[j].flow -= flow;
            return;
        }
    }
    Edge e = Edge(0, flow, u, v);
    edge.push_back(e);
}

bool Graph::push(int u) {
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].u == u) {
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (ver[u].h > ver[edge[i].v].h) {
                int flow = min(edge[i].capacity - edge[i].flow, ver[u].e_flow);
                ver[u].e_flow -= flow;
                ver[edge[i].v].e_flow += flow;
                edge[i].flow += flow;
                updateReverseEdgeFlow(i, flow);
                return true;
            }
        }
    }
    return false;
}

void Graph::relabel(int u) {
    int mh = INT_MAX;
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].u == u) {
            if (edge[i].flow == edge[i].capacity)
                continue;
            if (ver[edge[i].v].h < mh) {
                mh = ver[edge[i].v].h;
                ver[u].h = mh + 1;
            }
        }
    }
}

int Graph::getMaxFlow(int s, int t) {
    preflow(s);
    while (overFlowVertex(ver) != -1) {
        int u = overFlowVertex(ver);
        if (!push(u))
            relabel(u);
    }
    return ver.back().e_flow;
}

int main() {
    int V = 6;
    Graph g(V);
    g.addEdge(0, 1, 13);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 1, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(3, 4, 10);
    g.addEdge(1, 5, 7);
    g.addEdge(4, 5, 5);
    int s = 0, t = 5;
    cout << "Maximum flow is " << g.getMaxFlow(s, t);
    return 0;
}