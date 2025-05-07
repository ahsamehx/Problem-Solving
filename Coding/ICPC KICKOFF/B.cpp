#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int l = 0, r = 1e9 + 5;
    char c = ' ';
    int ans;

    while (true) {
        ans = l + (r - l) / 2;
        cout << ans << endl;
        cin >> c;

        if (c == '=') break;
        if (c == '>') {
            l = ans + 1;
        } else if (c == '<') {
            r = ans - 1;
        }
    }

    cout << "! " << ans << endl;
}
