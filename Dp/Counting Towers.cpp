#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e6;
#define mod 1000000007

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> dp(1e6+1, vector<int>(2, 0));
    dp[mx][0] = 1;
    dp[mx][1] = 1;
    for(int i =  mx - 1; i >= 0; i--) {
        dp[i][0] = (2 * dp[i+1][0]+ dp[i+1][1]) % mod;
        dp[i][1] = (4 * dp[i+1][1]+ dp[i+1][0]) % mod;
    }

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout << (dp[mx - n +1][0] + dp[mx - n + 1][1]) % mod << endl;
    }
}