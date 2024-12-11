#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;


    bool operator<(const Edge &e) const {
        return weight < e.weight;
    }
};


int findParent(int node, vector<int> &parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}


void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskalMST(int V, vector<Edge> &edges) {

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int edgeCount = 0;

    sort(edges.begin(), edges.end());

    for (const Edge &e : edges) {
        int rootU = findParent(e.u, parent);
        int rootV = findParent(e.v, parent);

        if (rootU != rootV) {
            mstWeight += e.weight;
            unionSets(e.u, e.v, parent, rank);
            edgeCount++;
        }

        if (edgeCount == V - 1) {
            break;
        }
    }

    return mstWeight;
}

int main() {
    int V, E;
    cout << "V=";
    cin >> V ;
    cout << "E=";
    cin >> E;

    vector<Edge> edges;

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    int mstWeight = kruskalMST(V, edges);

    cout << mstWeight << endl;

    return 0;
}
