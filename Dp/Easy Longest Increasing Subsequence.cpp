#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

int n;

vector<int> elements;
vector<int> dp;
//int solve(int i, int prev) {
//    if (i >= n) return 0;
//    int ans = 0;
//    if (dp[i][prev+1] != -1) {
//        return dp[i][prev+1];
//    }
//    ans = max(ans, solve(i + 1, prev));
//    if (elements[i] > elements[prev] or prev == -1) {
//        ans = max(ans, 1 + solve(i + 1, i));
//    }
//    return dp[i][prev + 1] = ans;
//}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n;
        elements = vector<int>(n + 1);
        dp = vector<int>(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            cin >> elements[i];
        }

        int longest = 1;
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j < i; j++) {
               if (elements[i] > elements[j]) {
                   dp[i] = max(dp[i], dp[j] + 1);
               }
           }
           longest = max(longest, dp[i]);
       }

        cout << longest << '\n';

        //cout << solve(0, -1) << endl;
    }
}