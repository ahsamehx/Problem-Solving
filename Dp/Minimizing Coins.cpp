#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

int n, target;
vector<int> coins;
vector<int> dp;

// int solve(int sum) {
//    if (sum > target) return inf;
//     if (sum == target) return 0;
//     if (dp[sum] != -1) return dp[sum];
//     int ans = inf;
//     for (auto val : coins) {
//         ans = min(ans, 1 + solve(sum + val));
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

    cin >> n >> target;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp.assign(target + 1, inf);
    //int result = solve(0);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) { //sum
        for (int j = 0; j < n; j++) { //coin index
            if (coins[j] <= i)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    int result = dp[target];
    if (result == inf) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}