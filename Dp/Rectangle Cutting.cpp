#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e9
#define mod 1000000007


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, inf));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            //making vertical cuts
            for (int h = 1; h <= j- 1; h++) {
                dp[i][j] = min({dp[i][j], dp[i][j-h]+ dp[i][h]+1});
            }
            //making horizontal cuts
            for (int h = 1; h <= i-1; h++) {
                dp[i][j] = min(dp[i][j], dp[i-h][j] + dp[h][j]+1);
            }
        }
    }
    cout << dp[a][b] << endl;

}