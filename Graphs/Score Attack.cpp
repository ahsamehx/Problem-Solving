#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

// //bool floyd(int n, vector<vector<int> > &adjmat) {
//     for (int k=0; k<n; k++) {
//         for (int i=0; i<n; i++) {
//             for (int j=0; j<n; j++) {
//                 if (adjmat[i][k] == -inf || adjmat[k][j] == -inf ) continue;
//                 adjmat[i][j] = max(adjmat[i][k], adjmat[k][j]);
//             }
//         }
//     }
//     for (int k=0; k<n; k++) {
//         if (adjmat[k][k] > -inf) return true;
//     }
//     return false;
// }

void bellman(int n, vector<array<int,3>> &edges, vector<int> &dist) {
    dist[0]=0;
    for(int i=0;i<n-1;i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] == -inf) continue;
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto [u, v, w] : edges) {
        if (dist[v] < dist[u] + w)
            dist[v] = inf;
    }
}

signed main() {
    int n, m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin>>u>>v>>w;
        edges.push_back({--u, --v, w});
    }
    vector<int> dist(n,-inf);
    bellman(n, edges, dist);

    cout << (dist[n-1] == inf? "inf" : to_string(dist[n-1])) << '\n';
}

