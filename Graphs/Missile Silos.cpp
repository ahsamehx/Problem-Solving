#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
const int N = 1e5;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m, src, l;
  cin>>n>>m>>src;
  vector<pair<int, int>> adj[n + 1];
  vector < pair<int, pair<int, int>>> edges(m);
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    edges.at(i) = make_pair(u, make_pair(v, w));
  }
  cin >> l;
  vector<int > dist(n + 1, inf);
  set<pair<int, int>> st{{dist[src] = 0, src}};
  while (!st.empty()) {
    auto [d, u] = *st.begin(); st.erase(st.begin());
    for(auto [v, w] : adj[u]) {
      if(dist[v] > d + w) {
        st.erase({dist[v], v});
        dist[v] = d + w;
        st.insert({dist[v], v});
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if (dist[i] == l) ans++;
  }
  for(auto [u, v] : edges) { //if the missile is on the edge
    int remL = l - dist[u];
    int remW = v.second - remL;
    if(remL > 0 && remL < v.second && l < dist[v.first] + remW) {
      ans++;
    }
    remL = l - dist[v.first];
    remW = v.second - remL;
    if(remL > 0 && remL < v.second && l <= dist[u] + remW) {
      ans++;
    }
  }
  cout << ans << '\n';

}