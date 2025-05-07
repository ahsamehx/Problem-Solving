#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> petals(n);

    for (int i = 0; i < n; i++) {
        cin >> petals[i];
    }

    sort(petals.begin(), petals.end());
    ll prefix = 0;
    ll result = 0;
    int left = 0, right = 0;
    while (right < n) {
        prefix += petals[right];
        while (petals[right] - petals[left] > 1) {
            prefix -= petals[left++];
        }
        while (prefix > m) {
            prefix -= petals[left++];
        }
        right++;
        result = max(result, prefix);
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
