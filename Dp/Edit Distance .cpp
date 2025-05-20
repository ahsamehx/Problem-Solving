#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int mx = 1e6;
#define mod 1000000007


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size(), m = str2.size();
    int mx = max(n, m);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1+ min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    cout << dp[n][m] << endl;


}