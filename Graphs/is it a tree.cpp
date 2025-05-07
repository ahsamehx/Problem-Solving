#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int node, int parent) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (!dfs(neighbor, node)) {
                return false;
            }
        } else if (neighbor != parent) {
            // If the neighbor is visited and not the parent, it's a cycle
            return false;
        }
    }
    return true;
}

bool isTree(int N, int M, vector<vector<int>>& adj) {
    if (M != N - 1) return false; // Condition for a tree: N nodes, N-1 edges

    if (!dfs(1, -1)) {
        return false;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) return false;
    }

    return true;
}

int main() {

    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isTree(N, M, adj)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
