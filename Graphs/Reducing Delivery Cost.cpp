#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
int n;

void dJK (int src, vector<vector<pair<int, int>>> adj,vector<int> &dist) {
    dist.assign(n, inf);
    dist[src] = 0;
    set<pair<int, int>> st;
    st.insert(make_pair(0, src));
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v]= dist[u] + w;
                st.erase({dist[v], v});
                st.insert({dist[v], v});
            }
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, k;
    cin>>n>>m>>k;
    vector<vector<pair<int, int>>> adj(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adj[--u].emplace_back(--v, w);
        adj[v].emplace_back(u, w);
        edges[i] = {u, v};
    }

    vector<vector<int>> dist(n);
    for (int i = 0; i < n; i++) {
        dJK(i,adj, dist[i]);
    }

    vector<pair<int, int>> ords;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin>>u>>v;
        ords.emplace_back(--u, --v);
    }
    int ans = inf;
    for (auto &[x, y] : edges) {
        int cur_cost = 0;
        for (auto &[u, v] : ords) {
            cur_cost+= min({dist[u][v]
                ,dist[u][x] + dist[y][v],
                dist[u][y] + dist[x][v]}
                );
        }
        ans = min(ans, cur_cost);
    }
    cout << ans << '\n';
}