#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e16

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  vector<array<int, 3>> edges;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    edges.push_back({u -1, v-1, w});
  }
  vector<bool> disabled(m, false);
  vector<int> ans;
  vector<array<int, 3>> queries; //type, a, b
  for (int i = 0; i < q; i++) {
    int type, a, b;
    cin >> type;
    if (type == 1) {
      cin >> a;
      a--;
      queries.push_back({type, a, 0});
      disabled[a] = true;
    }
    else if (type == 2) {
      cin >> a >> b;
      queries.push_back({type, a - 1, b -1});
    }
  }
  reverse(queries.begin(), queries.end());
  vector<vector<int>> floyd(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    floyd[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    if (disabled[i]) continue;
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      floyd[u][v] = floyd[v][u] = w;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
      }
    }
  }
  for (auto &q : queries) {
    int type = q[0], a = q[1], b = q[2];
    if (type == 1) { //add edge
      int u = edges[a][0], v = edges[a][1], w = edges[a][2];
      floyd[u][v] = floyd[v][u] = min(floyd[v][u], w);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          floyd[i][j] = min({floyd[i][j],
            floyd[i][u] + floyd[u][v] + floyd[v][j],
            floyd[i][v] + floyd[v][u] + floyd[u][j]
        });
        }
      }
    }
    else if (type == 2) {
      ans.push_back(floyd[a][b] == inf ? -1 : floyd[a][b]);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto val : ans)
    cout << val << endl;
}
