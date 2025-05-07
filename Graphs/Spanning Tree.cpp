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
};
int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &[w, u, v] : edges) {
        cin >> u >> v >> w;
        u--, v--;
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int res = 0;
    for (auto & [w, u, v] : edges) {
        if (dsu.merge(u, v)) {
            res+=w;
        }
    }

    cout << res << endl;

    return 0;
}
