#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007
int n, x;
vector<int> values;
//vector<vector<int>> dp(1e6 + 5, vector<int>(106, -1));

 // int solve(int sum=0, int i = 0){
 //     if (sum == x) return 1;
 //     if (sum > x || i >= n) return 0;
 //     if (dp[sum][i] != -1) return dp[sum][i];
 //     int ans = 0;
 //     //take the ith value
 //     ans = (ans + solve(sum + values[i], i))%mod;
 //     //leave the ith value
 //     ans = (ans + solve(sum, i+1))%mod;
 //
 //     return dp[sum][i] = ans;
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

     //cout << solve() % mod << endl;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {    // ith value
        for (int j = 1; j <= x; j++) {    // sum using ith value and the previous values
            if (j >= values[i-1])
                dp[j] = (dp[j] + dp[j - values[i-1]]) % mod;
        }
    }

    cout << dp[x] << '\n';

    return 0;
}