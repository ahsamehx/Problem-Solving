#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007

int n, m;
vector<int> values;
// vector<vector<int>> dp;
//
// int solve(int i, int prev_val){
//     if (i == n) return 1;
//
//     int ans = 0;
//     if (dp[i][prev_val] != -1) return dp[i][prev_val];
//
//     if (values[i] == 0) {
//         for (int num = max(prev_val-1 , 1LL); num <= min(prev_val+1, m); num++) {
//             if (abs(num - prev_val) <=1) {
//                 ans =(ans + solve(i+1, num))% mod;
//             }
//         }
//     }
//     else {
//         if (abs(values[i] - prev_val) <=1) {
//             ans = (ans +solve(i+1, values[i]))% mod;
//         }
//     }
//
//     return dp[i][prev_val] = ans;
// }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        values.push_back(x);
    }
    // dp.assign(n+1, vector<int>(m+1, -1));
    // if (values[0] == 0) {
    //     int ans = 0;
    //     for (int i = 1; i <= m; i++) {
    //         ans = (ans +solve(1, i))% mod;
    //     }
    //     cout << ans << endl;
    // }
    // else {
    //     cout << solve(1, values[0]) << endl;
    // }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (values[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][values[0]] = 1;
    }

    for (int i = 1; i < n; i++) {//index
        if (values[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
            }
        }
        else {
            int j = values[i];
            dp[i][j] = dp[i - 1][j];
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
        }
    }
    int result = 0;
    for (int i = 1; i <= m; i++) {
        result = (result + dp[n-1][i]) % mod;
    }
    cout << result << endl;
}