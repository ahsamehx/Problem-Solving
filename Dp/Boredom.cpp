#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
vector<int> freq, dp;

int solve(int n){
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    return dp[n] = max(solve(n - 1), solve(n - 2) + n *freq[n]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &val:v) cin>>val;
    int max_val = *max_element(v.begin(), v.end());
    freq.assign(max_val+1, 0);
    dp.assign(max_val+1, -1);
    for(auto val:v){
       freq[val]++;
    }
    cout << solve(max_val) << '\n';
}