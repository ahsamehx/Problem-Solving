#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

void floyed(int n, vector<vector<int> > &adjmat) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjmat[i][k] == inf || adjmat[k][j] == inf) continue;
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k]+adjmat[k][j]);
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, cnt = 1;
    cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<vector<int>> adjmat(n, vector<int>(n, inf));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>adjmat[i][j];
            }
        }
        for (int i=0; i<n; i++) {
            adjmat[i][i] = 0;
        }
        floyed(n, adjmat);
        int r;
        cin>>r;
        int total_d = 0;
        for (int i=0, u, v; i<r; i++) {
            cin>>u>>v;
            total_d += adjmat[--u][--v];
        }
        cout << "Case #" << cnt++ << ": " << total_d << endl;
    }
}