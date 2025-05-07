#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18
vector<vector<int>> dp;
vector<pair<int, int>> trees;

int solve(int i, bool cut_to_right) {
  if (i >= trees.size()) return 0;
  if (dp[i][cut_to_right] != -1) return dp[i][cut_to_right];
  int x = trees[i].first, h = trees[i].second;
  int ans = solve(i + 1, 0);   // dont cut the tree

  //cut to the left
  if (i == 0 || x - h > trees[i-1].first + (cut_to_right ? trees[i-1].second : 0) ) {
    ans = max(ans, 1 + solve(i + 1, 0));
  }
  // cut to the right
  if (i == trees.size() - 1 || x + h < trees[i+1].first) {
    ans = max(ans, 1 + solve(i + 1, 1));
  }

  return dp[i][cut_to_right] = ans;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  cin>>n;
  trees.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> trees[i].first >> trees[i].second;
  }
  dp.assign(n+1, vector<int>(2, -1));
  cout << solve(0, 0) << endl;
}
