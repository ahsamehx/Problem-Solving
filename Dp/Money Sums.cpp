#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int mx = 1e12;
#define mod 1000000007
vector<int> v;
set<int> st;
vector<vector<int>> dp;
int k = 0;
int n;


int solve (int i = 0, int sum = 0) {
    if(i == n){
        if (st.count(sum)==0 && sum != 0) {
            st.insert(sum);
            k++;
        }
        return 0;
    }
    if(dp[i][sum] != -1) {
        return dp[i][sum];
    }
    //skip the ith element
    int ans = 0;
    ans = solve(i + 1, sum);
    ans = solve(i + 1, sum + v[i]);

    return dp[i][sum] = ans;

}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    dp.assign(110, vector<int>(1e6+5, -1));

    solve();

    cout << k << endl;
    for (auto val : st) {
        cout << val << " ";
    }


}