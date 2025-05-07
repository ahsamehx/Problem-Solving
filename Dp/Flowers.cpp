#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
const int Max = 1e5+3;
int k;
vector<int> dp;

int solve(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    int red = solve(n - 1);
    int white = (k <= n ? solve(n-k): 0);
    return dp[n] = (red + white) % mod;

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t >> k;

    int prefix[Max];
    dp.resize(Max, -1);

    for (int i = 1; i < Max; i++) {
        solve(i);
    }
    prefix[0] = dp[0];
    for (int i = 1; i < Max; i++) {
        prefix[i] =(prefix[i-1] + dp[i]) % mod;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << (prefix[b] -(a > 0 ? prefix[a-1] : 0) + mod) % mod << '\n';
    }

}