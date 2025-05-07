#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

string s, t;
// int lcs(int i, int j) {
//     if (i >= s.size() || j >= t.size()) return 0;
//     int ans = 0;
//     if (dp[i][j] != -1) {
//         return dp[i][j];
//     }
//     ans = max(ans,  lcs(i + 1, j));
//     ans = max(ans, lcs(i, j + 1));
//     if (s[i] == t[j]) {
//         ans = max(ans, 1 + lcs(i + 1, j + 1));
//     }
//     return dp[i][j] = ans;
// }
//
void solve() {
    while (getline(cin, s), getline(cin, t)) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp (m + 5, vector<int> (n + 5, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] =dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[m][n] << endl;
    }
}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin>>t;
    while(t--) {
        solve();
    }
}