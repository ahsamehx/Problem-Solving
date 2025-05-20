#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e12;
#define mod 1000000007
vector<int> v1, v2, result;
vector<vector<int>> dp, paths;


int solve(int i = 0, int j = 0) {
    if (i >= v1.size() || j >= v2.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0, skip1, skip2;

    skip1 = solve(i+1, j);
    skip2 = solve(i, j+1);
    ans = skip1;
    paths[i][j] = 1;
    if (skip2> ans) {
        ans = skip2;
        paths[i][j] = 2;
    }
    if (v1.at(i) == v2.at(j)) {
        int match = solve(i+1, j+1) + 1;
        if (match > ans) {
            ans = match;
            paths[i][j] = 3;
        }
    }


    return dp[i][j] = ans;
}

void build(int i = 0, int j = 0) {
    while (i < v1.size() && j < v2.size()) {
        if (paths[i][j] == 1) {
            i++;
        }
        else if (paths[i][j] == 2) {
            j++;
        }
        else if (paths[i][j] == 3) {
            result.push_back(v1.at(i));
            i++, j++;
        }
    }
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= a; i++) {int x; cin >> x; v1.push_back(x);}
    for(int i = 1; i <= b; i++) {int x; cin >> x; v2.push_back(x);}
    dp.resize(a+1, vector<int>(b+1, -1));
    paths.resize(a+1, vector<int>(b+1, 0));
    cout << solve() << endl;
    build();
    for (auto val : result) cout << val << " ";


}