#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
#define mod 1000000007
int n;
char grid[1003][1003];
// vector<vector<int>> dp;
//
// int solve(int row, int col){
//     if (row > n || col > n) return 0;
//     if (row == n && col == n) return 1;
//     if (dp[row][col] != -1) return dp[row][col];
//     int ans = 0;
//     if (col +1 <= n && grid[row][col + 1] != '*')
//         ans = (ans + solve(row, col + 1))% mod;
//     if (row + 1 <= n && grid[row + 1][col] != '*')
//         ans = (ans + solve(row + 1, col))% mod;
//     return dp[row][col] = ans;
// }



signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin>>t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
          for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
          }
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[1][1] = (grid[1][1] == '.' )? 1:0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(grid[i][j] != '*') {
                    if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
                    if (i > 1) dp[i][j] =( dp[i][j] + dp[i-1][j])% mod;
                }
            }
        }
        cout << dp[n][n] << '\n';
        //dp.assign(n+2, vector<int>(n+2, -1));
        // if (grid[1][1] == '*' || grid[n][n] == '*') {
        //     cout << 0 << endl;
        // }
        // else {
        //      cout << solve(1, 1) % mod << endl;
        // }
    }

}