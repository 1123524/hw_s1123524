#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;


vector<int> bfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> bfsResult;
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfsResult;
}

int main() {
    int V;
    cout << "Please enter the number of nodes:";
    cin >> V;
    cin.ignore();

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            adj[i].push_back(neighbor);
        }
    }

    vector<int> bfsResult = bfsTraversal(V, adj);

    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
