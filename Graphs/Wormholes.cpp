#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

bool bellmanNegCycle(int n, int src, vector<array<int, 3>> &edges) {
    vector<int> dist(n, inf);
    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (w == inf) continue;
            if (dist[u] + w < dist[v]) {
                if (i == n - 1) return true;
                dist[v] = dist[u] + w;
            }
        }
    }
    return false;
}

signed main () {
    int t;
    cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector<array<int, 3>> edges;
        for(int i=0, u, v, w;i<m;i++) {
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }
        //add the suffle function here
        random_device rd;
        mt19937 g(rd());
        random_shuffle(edges.begin(), edges.end(), g);
        cout << (bellmanNegCycle(n, 0, edges)? "possible" : "not possible") << '\n';

    }
}