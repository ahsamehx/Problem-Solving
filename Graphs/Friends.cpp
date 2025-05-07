//
// Created by edoga on 1/31/2025.

#include <bits/stdc++.h>
using namespace std;


int n, m, answer;

void dfs (int u, vector<vector<int>>& adj, vector<int> &visited) {
    answer++;
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
           dfs(v, adj, visited);
        }
    }
}


int main() {
  int t;
  cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> adj(n +1);
        vector<int> visited (n +1, 0);
        answer = 0;
        int mx = 0;
        for (int i =0 ; i < m ; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i =1 ; i <= n ; i++) {
          if (!visited[i]) {
            dfs(i, adj, visited);
            mx = max(mx, answer);
            answer = 0;
          }
        }
        cout << mx << endl;
    }
}
