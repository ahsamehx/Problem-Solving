#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

vector<int> Dijkstra (int n, int src, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, inf);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st; // (cost, node)
    st.emplace(0, src);

    while (!st.empty()) {
        auto [d, u] = st.top();
        st.pop();
        if (dist[u] < d ) continue;
        for (auto [v, w] :  adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                st.emplace(dist[v], v);
            }
        }
    }
    return dist;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n >> m >> q;

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w });
        adj[v].push_back({u,w});
    }
    while(q--) {
        cin>>m;
        vector<int> dist = Dijkstra(n, m, adj);
        int max_dist = 0, count = 0;
        for (auto val : dist) {
            if (val != inf) {
                if (val > max_dist) {
                    max_dist = val;
                    count = 1;
                }
                else if (val == max_dist) {
                    count++;
                }
            }
        }

        cout << max_dist <<" "<<count << "\n";
    }
    return 0;
}
