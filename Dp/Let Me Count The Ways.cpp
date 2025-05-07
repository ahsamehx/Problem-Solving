#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> dp;
int coins[5] = {1, 5, 10, 25, 50};

int solve(int n, int i, int curSum = 0) {
    if (i >= 5) return 0;
    if (curSum > n) return 0;
    if (curSum == n) return 1;

    if (dp[i][curSum] != -1) return dp[i][curSum];
    int ans = 0;
    ans += solve(n, i, curSum + coins[i]) + solve(n, i+1, curSum);
    return dp[i][curSum] = ans;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin>>n) {
        dp.assign(5, vector<int>(n+1,-1));
        int ans = solve(n, 0);
        if (ans == 1)
            cout << "There is only " << 1 << " way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;

    }
}