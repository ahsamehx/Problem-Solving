#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 1e16
int n, c;
vector<int>a, b;
int dp[200005][2];
int solve(int floor, bool elevatorUsed){
    if (floor == 1) return elevatorUsed? c : 0;
  if (dp[floor][elevatorUsed] != -1) return dp[floor][elevatorUsed];
  int ans = inf;
  if (elevatorUsed) {
    ans = min({ans, solve(floor - 1, 1) + b[floor -2], solve(floor-1, 0) + c + b[floor-2]});
  }
  else {
    ans = min({ans, solve(floor - 1, 0) + a[floor -2], solve(floor-1, 1) + a[floor-2]});
  }
  return dp[floor][elevatorUsed] = ans;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> c;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n -1; i++) {
    int x; cin >> x;
    a.emplace_back(x);
  }
  for(int i = 0; i < n -1; i++) {
    int x; cin >> x;
    b.emplace_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cout << min(solve(i, 0), solve(i, 1)) << " ";
  }
}