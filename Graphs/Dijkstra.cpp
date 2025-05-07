#include<bits/stdc++.h>
#define int long long
#define inf 1e16
using namespace std;

vector<pair<int, int>> Dijkstra(int n ,vector<vector<pair<int,int>>> adj)
{
  int src = 0;
  vector<pair<int, int>> dist(n,make_pair(inf, -1));// d, par
  dist[src] = make_pair(0, 0);
  set<pair<int, int>> st;  //cost, node
  st.emplace(make_pair(0,src));
  while(st.size())
    {
      auto [d,u] = *st.begin();
      st.erase(st.begin());
      if(dist[u].first < d) continue;
      for(auto [v,w] : adj[u]){
        int new_d = dist[u].first + w;
        if(dist[v].first > new_d)
          {
            st.erase({dist[v].first, v});
            dist[v].first = new_d;
            dist[v].second = u; // parent
            st.emplace(make_pair(new_d,v));
          }

      }
    }
    return dist;
}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin>>n>>m;
  vector<vector<pair<int,int>>> adj(n);
  for(int i=0;i<m;i++){
    int u, v, w;
    cin>>u>>v>>w;
    u--, v--;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  vector<pair<int, int>> dis = Dijkstra(n, adj);

  if (dis[n-1].first == inf)
    cout<<"-1";
  else {
    vector<int> path;
    int node = n - 1;

    while (node != -1) {
      path.push_back(node);
      if (node == 0) break;
      node = dis[node].second;
    }

    reverse(path.begin(), path.end());

    for (auto val : path) {
      cout<<val + 1<<" ";
    }
  }
}