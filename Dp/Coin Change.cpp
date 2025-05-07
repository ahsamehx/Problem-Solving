#include <bits/stdc++.h>
using namespace std;
int n = 8000;
//vector<vector<int>> dp;
//int coinChange(vector<int> &coins, int i = 0, int cur_sum = 0) {
//    if (cur_sum == n) return 1;
//    if (cur_sum > n) return 0;
//    if (i >= coins.size()) return 0;
//    if (dp[i][cur_sum] != -1) return dp[i][cur_sum];
//    int ans = 0;
//    ans +=coinChange(coins, i + 1, cur_sum);
//    if (cur_sum + coins[i] <= n) {
//        ans +=coinChange(coins, i, cur_sum + coins[i]);
//    }
//    return dp[i][cur_sum] = ans;
//}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> coins= {50, 25, 10, 5, 1};
    while (cin >> n) {
        //dp.assign(coins.size()+1, vector<int>(n + 1 , 0));
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= coins.size(); i++) {
            dp[0] = 1;
        }

        for (int i = 1; i <= coins.size(); i++) {
            for (int amount = coins[i-1]; amount <= n; amount++) {
                if (coins[i -1] <= amount) {
                    dp[amount] = dp[amount] + dp[amount - coins[i - 1]];
                }
            }
        }
        //int ans = coinChange(coins, 0, 0);
        cout <<  dp [n] << endl;
    }
}




