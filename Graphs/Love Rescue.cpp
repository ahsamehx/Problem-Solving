#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU {
    vector<int> par, sz;
    DSU() {}
    DSU(int n){init(n);}
    void init(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    bool merge (int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v); // u is smaller
        sz[v] += sz[u];
        par[u] = v;
        return true;
    }
    bool same (int u, int v) {
        return find(u) == find(v);
    }
    int size () {
        int mx = 0;
        for (int i = 0; i < sz.size(); i++) {
            mx = max(mx, sz[i]);
        }
        return mx;
    }
};
int32_t main() {
    int n;
    cin >> n;
    string s0, s1;
    cin >> s0 >> s1;
    DSU dsu(26);
    int res = 0;
    vector<pair < char, char>> spell;
    for (int i = 0; i < n; i++) {
        int u, v;
        u = s0[i] - 'a';
        v = s1[i] - 'a';
        if (u != v) {
            if (dsu.merge(u, v)) {
                res++;
                spell.emplace_back(s0[i], s1[i]);
            }
        }
    }
    cout << res << endl;
    for (auto p : spell) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
