#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
bool cyclic = false;

bool isTree(int N, int M, vector<vector<int>>& adj) {
    if (M != N - 1) return false; // Condition for a tree: N nodes, N-1 edges

    queue<pair<int, int>> q;
    q.push({1, -1});
    visited[1] = true;
    while (!q.empty()) {
        int n = q.front().first;
        int par = q.front().second;
        q.pop();
        for (int v : adj[n]) {
            if (!visited[v]) {
                q.push({v, n});
                visited[v] = true;
            }
            else if (v != par) {
                cyclic = true;
                break;
            }
        }
    }

    if (cyclic) return false; // cycle was detected

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) return false; //not connected
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
