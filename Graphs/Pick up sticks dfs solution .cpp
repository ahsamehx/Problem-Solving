//
// Created by edoga on 1/31/2025.
//
#include <bits/stdc++.h>
using namespace std;


int n, m;
bool cyclic = false;

void dfs (int u, vector<vector<int>>& adj, vector<int> &visited, stack<int> &st) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
        else if (visited[v] == 1) {
            cyclic = true;
            return;
        }
    }
    visited[u] = 2;
    st.push(u);
}

void topological (vector<vector<int>>& adj, vector<int> &visited, stack<int> &st) {
    for (int i = 1; i <= n && !cyclic; i++) {
        if (!visited[i]) {
            dfs(i,adj,visited,st);
        }
    }
}


int main() {
    cin >> n >> m;
    while (n != 0 && m != 0) {
        vector<vector<int>> adj(n +1);
        vector<int> visited (n +1, 0);
        stack<int> st;

        for (int i =0 ; i < m ; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        topological(adj, visited, st);
        if (cyclic) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            while(!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
        }

        cin >> n >> m;
        cyclic = false;
    }
}