#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> visited(2001);
vector<vector<int>> adj(2001);
//stack<int> s;
int bfs(int n) {
    int levels = 0;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty()) {
        int size = q.size();
        levels++;
        while (size--) {
            int node = q.front();
            q.pop();
            for (auto p : adj[node]) {
                if (!visited[p]) {
                    visited[p] = true;
                    q.push(p);
                }
            }
        }
    }
    return levels;
}

int32_t main() {
    // solution is number of level of the largest component
    int n;
    cin >> n;
    vector<int> roots;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x != -1)
                adj[x].push_back(i);
            else
                roots.push_back(i);
        }
        int answer = 0;
        for (auto i : roots) {
            if (!visited[i]) {
                answer = max(answer, bfs(i));
            }
        }
        cout << answer << endl;
}