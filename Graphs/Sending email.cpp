#include<bits/stdc++.h>
#define int long long
#define inf 1e16
using namespace std;

vector<int> Dijkstra (int n, int src, vector<vector<pair<int, int>>> adj) {
  vector<int> dist(n, inf);
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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  int cnt = 0;
  while(t--) {
    cnt++;
    int n, m, src, dest;
    cin>>n>>m>>src>>dest;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++) {
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }

    vector<int> dist = Dijkstra(n, src, adj);
    cout << "Case #" << cnt << ": ";
    if (dist[dest] == inf) {
      cout << "unreachable" << endl;
    }
    else {
      cout << dist[dest] << endl;
    }

  }

}