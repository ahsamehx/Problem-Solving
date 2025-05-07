#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, k;
int dp[2005][2005];

int solve(int pos, int last) {
    if (pos == k) return 1;
    if (dp[pos][last] != -1)
        return dp[pos][last];
    int result = 0;
    for (int i = last; i <= n; i+=last) {
        result = (result + solve(pos + 1, i)) % mod;
    }
    return dp[pos][last] = result;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result =( result + solve(1, i)) % mod;
    }
    cout << result << '\n';
}