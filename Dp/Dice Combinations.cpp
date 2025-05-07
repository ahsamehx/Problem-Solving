#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;

int arr[6]={1,2,3,4,5,6};
vector<int> dp;
int n;

// int solve(int sum) {
//     if (sum > n ) return 0;
//     if (sum == n) return 1;
//     if (dp[sum] != -1) return dp[sum];
//     int ans = 0;
//
//     for (int j = 0; j < 6; j++) {
//         ans = (ans+ solve(sum + arr[j])) % mod;
//     }
//     return dp[sum] = ans;
// }

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    dp.assign(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {    //sum
        for (int j = 1; j <= 6; j++) { // coin
            if (j <= i) {
                dp[i]= (dp[i-j]+ dp[i]) % mod;
            }
        }
    }
    cout << dp[n] << '\n';
    //cout << solve(0) % mod<< endl;

}