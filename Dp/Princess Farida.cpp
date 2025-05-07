#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dp;
int cnt = 0;
//int calc(int n, vector<int>& monsters, int i) {
//  if (i >= n) return 0;
//  int ans = 0;
//  if (dp[i] != -1) {
//    return dp[i];
//  }
//  ans = max(ans , calc(n, monsters, i + 1));
//  ans = max(ans, monsters[i] +calc( n, monsters, i + 2));
//  return dp[i] = ans;
//}

void solve() {
  int n;
  cin >> n;
  vector<int> monsters(n);
  for (int i = 0; i < n; i++) {
    cin >> monsters[i];
  }
  dp.assign(n + 3, 0);

  if (n > 0) dp[1] = monsters[0];
  for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i- 1], dp[i-2] + monsters[i - 1]);
  }
  cout << "Case "<< cnt <<": " << dp[n] << endl;

  //cout << "Case "<< cnt <<": " << calc(n, monsters, 0) << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int tc = 1;
  cin >> tc;
  while (tc--) {
    cnt++;
    solve();
  }
}