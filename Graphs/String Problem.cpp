#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 205

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s, f;
  cin>>s>>f;
  if (s.length() != f.length()) {
    cout << -1 << endl;
    return 0;
  }
  int n=s.length();
  int m; cin>>m;
  int adjmat[26][26];
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      adjmat[i][j] = inf;
    }
  }
  for (int i = 0, w; i < m; i++) {
    char a,b;
    cin>>a>>b >> w;
    a = a - 'a', b = b - 'a';
    adjmat[a][b] = min(adjmat[a][b], w);
  }
  for (int i = 0; i < 26; i++) {
    adjmat[i][i] = 0;
  }
  //floyd warshall
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (adjmat[i][k] == inf || adjmat[k][j] == inf) continue;
        adjmat[i][j] = min(adjmat[i][j], adjmat[i][k]+ adjmat[k][j]);
      }
    }
  }
  string str = "";
  int ans = 0;
  bool flag = true;
  for (int i = 0; i< n; i++){
    char c = s[i];
    int co = 0;
    if (s[i] != f[i]) {
      int cost = inf;
      flag = false;
      for (int k =0; k< 26; k++) {
        if (adjmat[s[i]-'a'][k] == inf || adjmat[f[i]-'a'][k] == inf) continue;
        co = adjmat[s[i]-'a'][k] + adjmat[f[i]-'a'][k];
        flag = true;
        if (co < cost) {
          cost = co;
          c = k + 'a';
        }
      }
      ans+= cost;
    }
    if (!flag) break;
    str+=c;
  }

  if (flag) {
    cout << ans << endl << str << endl;
  }
  else {
  cout << -1 << endl;
  }
}