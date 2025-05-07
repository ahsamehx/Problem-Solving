#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18

bool bs (int n, int x, int y) {
    return (n + x > y && x + y > n && y + n > x);
}

signed main() {
    int t;
    cin>>t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(auto &val: v) cin >> val;
            int sum = 0;
        for (auto val : v) sum+= val;
        cout << sum - n +1 << endl;
    }
}