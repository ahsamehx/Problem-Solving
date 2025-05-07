#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define inf 1e18
#define mod 1000000007
int n, x;
vector<int> prices, pages;
// vector<vector<int>> dp;
//
// int solve(int avail_money, int i) {  //got TLE
//     if (i >= n) return 0;
//     //if (x == 0) return 0;
//
//     if (dp[avail_money][i] != -1) return dp[avail_money][i];
//
//     int ans = 0;
//     //take the current book
//     if (avail_money - prices[i] >= 0) {
//         ans = max(ans, solve(avail_money - prices[i], i + 1) + pages[i]);
//     }
//     //leave the current book
//     ans = max(ans, solve(avail_money, i + 1));
//
//     return dp[avail_money][i] = ans;
// }


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin>>t;
    while(t--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            int p; cin >> p;
            prices.push_back(p);
        }
        for (int i = 1; i <= n; i++) {
            int p; cin >> p;
            pages.push_back(p);
        }

        vector<int> dp(x + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {     //for each book
            for (int j = 0; j <= x; j++) {
                if (j - prices[i] >= 0) {
                    dp[j] = max(dp[j], dp[j-prices[i]] + pages[i]);
                }
            }
        }

        cout << dp[x] << '\n';



        // dp.assign(x + 1, vector<int>(n+1, -1));
        //
        // cout << solve(x, 0) << endl;

    }

}