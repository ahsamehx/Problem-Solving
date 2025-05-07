#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
int n;
// vector<int> dp;
// int solve(int total = n) {
//     if (total == 0) return 0;
//     if (total == -1) return -1;
//     if (dp[total] != -1) return dp[total];
//
//     int ans = inf;
//     int temp = total;
//     while (temp > 0) {
//         int x = temp % 10;
//         temp /= 10;
//         if (x > 0)
//             ans = min(ans, 1 + solve(total-x));
//     }
//     return dp[total] =  ans;
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
        vector<int> dp(n+1, inf);
        for (int i = 0; i < 10; i++) {
            dp[i] = i;
        }
        for (int i = 0; i <= n; i++) {   //total value
            int temp = i;
            while (temp > 0) {
                int x = temp % 10;
                temp = temp / 10;
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
        cout << dp[n];

        //cout << solve() << endl;
    }

}