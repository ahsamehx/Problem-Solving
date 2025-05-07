#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t;
  cin>>t;
  while(t--) {
    int k, q;
    cin>>k>>q;
    vector<int> n(q);
    vector<int> st;
    for(int i=0, u; i<k; i++) {
      cin>>u;
      st.push_back(u);
    }
    for(int i=0; i<q; i++) {
      cin >> n[i];
    }
    int index = *st.begin();

    for(int i=0; i<q; i++) {
      cout << (index <= n[i] ? index - 1 : n[i]) << ' ';
    }
    cout << '\n';
  }
}