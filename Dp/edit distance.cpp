#include<bits/stdc++.h>
#define int long long
using namespace std;
string s, t;

int dpRecursive (int i, int j, int n, int m, vector<vector<int> > &dp) {
  if (i == n) return m - j;
  if (j == m) return n - i;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 1e9;
  if (s[i] == t[j]) {
    ans = dpRecursive(i+1, j+1, n, m, dp);
  }
  else {
    ans = min({ans, 1 + dpRecursive(i+1, j, n, m, dp), 1 + dpRecursive(i, j+1, n, m, dp), 1 + dpRecursive(i+1, j +1, n, m, dp)});
  }
  return dp[i][j] = ans;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int tc; cin >> tc;
  while(tc--) {
    cin >> s >> t;
    int n = s.length(); //  A
    int m = t.length();  // B
    vector<vector<int> > dp(n+1, vector<int> (m+1, -1));
    cout << dpRecursive(0, 0, n, m, dp) << endl;
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // for (int i = 0; i <= n; i++) {
    //   dp[i][0] = i;
    //   dp[0][i] = i;
    // }
    //
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= m; j++) {
    //     if (s[i-1] == t[j-1]) {
    //       dp[i][j] = dp[i-1][j-1];
    //     }
    //     else {
    //       dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
    //     }
    //   }
    // }
    // cout << dp[n][m] << '\n';
  }
}