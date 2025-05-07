#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

vector<vector<int>> origin(501, vector<int>(501, 0));
void floyd (int n,int x,vector<vector<int>>& adjmat) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == x || j == x) continue;
            origin[i][j] = adjmat[i][j];
        }
    }

    //floyd
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (origin[i][k] == inf && origin[k][j] == inf) continue;
                origin[i][j] = min(origin[i][k] + origin[k][j], origin[i][j]);
            }
        }
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (origin[i][j] == inf) continue;
            num+=origin[i][j];
        }
    }
    cout << num << " ";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> adjmat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin>>adjmat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            floyd(n, x, adjmat);
        }
    }

}