#include <bits/stdc++.h>
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
int main() {
    int n, m , q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {int x; cin >> x >> x; }
    DSU dsu(n);
    vector<array<int, 3>> queries(q);
    string s;
    for (auto& [type, u, v]:queries) {
        cin >> s >> u >> v;
        --u, --v;
        type = (s[0] == 'c');
    }
    vector<bool> res;
    for (int i = q - 1; i >= 0; i--) {
        auto [type, u, v] = queries[i];
        if (type) {
            dsu.merge(u, v);
        }else {
            res.push_back(dsu.same(u, v));
        }
    }
    for (int i = (int)res.size() - 1; i >= 0; i--) {
        cout << (res[i] ? "YES" : "NO") << endl;
    }




    return 0;
}
