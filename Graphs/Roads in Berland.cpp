#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>> n;
    vector<vector<int>> adjMat(n, vector<int>(n , 0));
    for(int i=0, u, v, w;i<n;i++) {
           for (int j=0, v, w;j<n;j++) {
               cin >> w;
               adjMat[i][j]=w;
           }
    }

    cin >> k;
    for(int s=0, u, v, w; s<k; s++) {
        cin>>u>>v>>w;
        u--, v--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMat[i][j]=min({adjMat[i][j],
                    adjMat[i][u]+ w + adjMat[v][j],
                    adjMat[i][v]+ w + adjMat[u][j]});
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum+=adjMat[i][j];
            }
        }
        cout << sum/2 << " ";
    }
}