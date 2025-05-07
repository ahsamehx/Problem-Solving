#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> colors;

bool dfs(int u, int color) {
    colors[u] = color;
    for (auto n : adj[u]) {
        if (colors[n] == -1) {
            if (!dfs(n, 1 - color)){
                return false;
            }
        }else if (colors[n] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int N) {
    for (int i = 1; i <= N; i++) {
        if (colors[i] == -1) {
            if (!dfs(i, 0)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> N >> M;
        adj.clear();
        adj.resize(N + 1);
        colors.assign(N +1, -1);

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBipartite(N)) {
            cout << "Scenario #" << cnt << ":" <<endl << "No suspicious bugs found!" << endl;
        } else {
            cout << "Scenario #" << cnt << ":" <<endl << "Suspicious bugs found!" << endl;
        }
        cnt++;
    }
    return 0;

}
