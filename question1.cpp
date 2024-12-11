#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjList(int V, vector<pair<int, int>> &edges) {
    vector<vector<int>> adjList(V);
    for (auto &edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    return adjList;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> adjList = createAdjList(V, edges);
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

