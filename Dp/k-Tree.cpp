#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, k, d;
int dp[108][2];

int solve(int sum, bool flag){
  if (sum == n) return (flag)?1:0;
  if (sum > n) return 0;
  if (dp[sum][flag] != -1) return dp[sum][flag];
  int result = 0;
  for (int i = 1; i <=k; i++) {
    bool flag2 = flag || (i >= d);
    result = (result + solve(sum + i, flag2)) % mod;
  }
  return dp[sum][flag] = result;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif
  cin >> n >> k >> d;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0) << "\n";

}