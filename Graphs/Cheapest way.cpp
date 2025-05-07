#include<bits/stdc++.h>
#define int long long
#define inf 1e16
using namespace std;

vector<int> Dijkstra (int n, int src, vector<vector<pair<int, int>>> adj, map<string,pair<int, int>> station_cost) {
    vector<int> dist(n, inf);
    map <string, string> parent;
    dist[src] = 0;
    set<pair<int, int>> st; // (cost, node)
    st.emplace(0, src);


    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        if (dist[u] < d ) continue;
        for (auto [v, w] :  adj[u]) {
            if (dist[v] > dist[u] + w) {
                st.erase({dist[v], v});
                dist[v] = dist[u] + w;
                st.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int cal () {

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int map_cnt = 0;
    while(t--) {
        int n, m;
        cin>>n;
        map<string,pair<int, int>> station_cost; // (name, cost, id) station section
        for (int i = 0, w; i < n; i++) {
            string s;
            cin>> s >> w;
            station_cost[s].first = w;
            station_cost[s].second = i; // id starts from 0 --> n -1
        }
        cin >> m;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++) {
            int u,v,w;
            string src,dest;
            cin >> src >> dest >> w;
            u = station_cost[src].second;
            v = station_cost[dest].second;
            adj[u].push_back({v,w * 2});
            adj[v].push_back({u,w * 2}); //*2 for oil consumption 
        }
    }

}