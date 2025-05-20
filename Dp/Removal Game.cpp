#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

int n, target;
vector<int> values;
vector<int> dp;

int solve(int i = 0, int sum = 0) {
  
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    values.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> values[i];
    }

    cout << solve() << endl;

    return 0;
}