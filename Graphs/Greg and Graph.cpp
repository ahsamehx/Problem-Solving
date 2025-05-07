#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e12

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> orgMat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>orgMat[i][j];
        }
    }

    vector<vector<int>> adjMat(n, vector<int>(n, inf));
    vector<int> rm;
    vector<int> inGraph;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        rm.push_back(x-1);
    }
    vector<int> ans;
    for (int x = rm.size() - 1; x >= 0; x--) {
        int u = rm[x];
        inGraph.push_back(u);
        for (int v = 0; v < n; v++) {
            adjMat[u][v] = min(adjMat[u][v], orgMat[u][v]);
            adjMat[v][u] = min(adjMat[v][u], orgMat[v][u]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMat[i][u] == inf || adjMat[u][j] == inf) continue;
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][u] + adjMat[u][j]);
            }
        }
        int sum = 0;

        for (auto v : inGraph) {
            for (auto u : inGraph) {
                sum += adjMat[v][u];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (auto v : ans) {
        cout<<v<<" ";
    }
}
