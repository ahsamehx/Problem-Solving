#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

signed main() {
  int t;
  cin>>t;
   while(t--)
     {
     int n, m, x, y;
       cin>>n>>m>>x>>y;
     cout << (n == m && n == x && n == y ? "Yes" : "NO") << endl;
     }
}