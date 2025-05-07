#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
const int N = 1e4;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m, k;
  cin>>n>>m>>k;
  vector<array<int, 3>>adj[N];

  for(int i=0, u, v, w; i<m; i++) {
    cin>>u>>v>>w;
    adj[u].push_back({v, w, 0});
    adj[v].push_back({u, w, 0});
  }
  for(int i=0, w, v; i<k; i++) {
    cin>>v>>w;
    adj[1].push_back({v, w, 1});
  }
  vector<pair<int, int>>dist(n+1,{inf, 0});
  dist[1] = {0,0};
  set<array<int, 3>>st({{0,0,1}});
  while(st.size()) {
    auto [d, is_train, u] = *st.begin();
    st.erase(st.begin());
    if(is_train) {k--;}
    for(auto [v, w, is] : adj[u]) {
      pair<int, int> new_dist = {d + w, is};
      if(new_dist < dist[v]) {
        st.erase({dist[v].first, dist[v].second, v});
        dist[v] = new_dist;
        st.insert({dist[v].first, dist[v].second, v});
      }
    }

  }
  cout << k << endl;
}