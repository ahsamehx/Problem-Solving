#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007
int n, x;
vector<int> values;
//vector<int> dp (1e6, -1);
//
// int solve(int sum=0){
//     if (sum == x) return 1;
//     if (sum > x) return 0;
//     if (dp[sum] != -1) return dp[sum];
//     int ans = 0;
//     for (int i = 1; i <= n; i++) {
//         ans = (ans + solve(sum + values[i-1])) % mod;
//     }
//     return dp[sum] = ans;
// }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        values.push_back(c);
    }

   // cout << solve() % mod << endl;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= values[j-1])
                dp[i] = (dp[i] + dp[i - values[j-1]]) % mod;
        }
    }

    cout << dp[x] << '\n';

    return 0;
}