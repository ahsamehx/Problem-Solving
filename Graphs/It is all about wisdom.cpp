#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

bool check(int n, vector<array<int, 3>> adj[], int final, int k) {
    vector<int> dist(final, inf);
    dist[0] = 0;
    set<pair<int, int>> st{{dist[0], 0}};
    while (st.size()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());
        //if (d >= k) return false;
        //if (u + 1 == final) return true;
        for (auto [v, w, key]: adj[u]) {
            if (key> n) continue;
            int new_d = dist[u] + w;
            if (new_d < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = new_d;
                st.insert({dist[v], v});
            }
        }
    }
    return (dist[final -1 ] < k);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, m , k;
        cin>>n>>m>>k;
        vector<array<int, 3>> adj[n];
        vector<int> vals;
        for(int i=0, u, v,w, key;i<m;i++) {
            cin>>u>>v>> w >> key;
            vals.push_back(key);
            u--; v--;
            adj[u].emplace_back(array<int, 3>{v, w, key});
            adj[v].emplace_back(array<int, 3>{u, w, key});
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int l = 0, r = vals.size() - 1, mid, ans = -1;
        while(l<=r) {
            mid = l + (r-l)/2;
            int valid = vals[mid];
            if (check(valid, adj, n, k)) {r = mid - 1; ans = valid;}
            else l = mid + 1;
        }
        cout<<ans<<"\n";
    }
}