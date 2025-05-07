#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Dijkstra(int src, int n, vector<vector<pair<int,int>>> adj) {
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    set<pair<int,int>> st; // cost -- vertex
    st.emplace(make_pair(0, src));
    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        if (dis[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            int new_dis = dis[u] + w;
            if (dis[v] > new_dis) {
                st.erase({dis[v], v});
                dis[v] = new_dis;
                st.emplace(make_pair(dis[v], v));
            }
        }
    }
    return dis;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, src, dest;
        cin >> n >> m >> src >> dest;
        src--; dest--;
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            u--, v--;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int> dis = Dijkstra(src, n, adj);

        if (dis[dest] == INT_MAX) cout << "NONE\n";
        else cout << dis[dest] << "\n";
    }


    return 0;
}
