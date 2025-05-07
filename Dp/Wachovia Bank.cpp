#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

int n;

vector<pair<int, int>> items;
vector<vector<int>> dp;

signed main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int w;
        cin >> w >> n;
        items = vector<pair<int, int>>(n + 1);
        dp = vector<vector<int>>(n + 1, vector<int>(w + 1, 0));
        for (int i = 1; i <= n; i++) {
            cin >> items[i].first >> items[i].second;
        }


        for (int i = 1; i <= n; i++) {
            for (int amount = 0; amount <= w; amount++) {
                dp[i][amount] = dp[i -1][amount];
                if (items[i].first <= amount) {
                    dp[i][amount] = max(dp[i -1][amount], items[i].second + dp[i-1][amount - items[i].first]);
                }
            }
        }

        cout << "Hey stupid robber, you can get " << dp[n][w] << '.' << endl;
    }
}