#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

void solve(int n, vector<array<int, 3>> &edges) {
    vector<int> dist(n, 0);
    int mn = inf;
    for(int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            mn = min(mn, dist[u] + w);
            if (dist[u] + w < dist[v]) {
                if (i == n - 1) {
                    cout << "-inf" << endl;
                    return;
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    cout << mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<array<int,3>>edges;
        for(int i=0, u, v, w;i<m;i++) {
            cin >> u >> v >> w;
            edges.push_back({--u,--v,w});
        }
        solve(n,edges);

        //cout<< (result == -inf ? "-inf" : to_string(result)) << "\n";
    }
}