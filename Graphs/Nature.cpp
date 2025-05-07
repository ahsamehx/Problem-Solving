#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> visited (5001, false);
map <string, int> mp;
vector<vector<int>> adj(5001);
stack<int> s;

void dfs(int n) {
    visited[n] = 1;
    for (int i = 0; i < adj[n].size(); i++) {
        if (!visited[adj[n][i]]) {
            dfs(adj[n][i]);
        }
    }
    s.push(n);
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        mp.clear();
        visited.assign(n, false);
        adj.assign(n, vector<int>());
        string str ;
        for (int i = 0; i < n; i++) {
            cin >> str;
            mp.insert(make_pair(str, i));
        }
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            adj[mp[v]].push_back(mp[u]);
        }
        //traversing for dfs
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }

        int ans = 0;
        vector <int> longest(n, 1);
        while (s.empty() == false) {
            int node = s.top();
            s.pop();
            for (auto nbr : adj[node]) {
                longest[nbr] = max(longest[nbr], longest[node] + 1);
                ans = max(ans, longest[nbr]);
            }
        }

        cout << ans << endl;

        cin >> n >> m;
    }
}