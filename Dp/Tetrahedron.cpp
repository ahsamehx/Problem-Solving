#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int a = 0, b = 0, c = 0, d = 1;
    for(int i = 1; i <= n; i++) {
        int na = (b + c + d) % mod;
        int nb = (a + c + d) % mod;
        int nc = (a + b + d) % mod;
        int nd = (a + c + b) % mod;

        a = na; b = nb; c = nc; d = nd;
    }
    cout << d << '\n';
}