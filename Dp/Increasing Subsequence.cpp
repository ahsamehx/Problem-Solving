#include <bits/stdc++.h>
using namespace std;
#define inf 1e18

int n, target;
vector<int> values;
// vector<vector<int>> dp;
//
// int solve(int i = 0, int prev = -1) {
//     if (i == n) return 0;
//     if (dp[i][prev+1]!= -1) return dp[i][prev+1];
//
//     int ans = 0;
//
//     ans = solve(i+1, prev);
//     if (prev == -1 || values[i] > values[prev]){
//
//         ans = max(ans , solve(i+1, i) +1);
//     }
//
//     return dp[i][prev+1] = ans;
// }


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    values.resize(n);
    vector<int> dp(n + 1, 1);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (values[i] > values[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}