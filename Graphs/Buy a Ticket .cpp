#include<bits/stdc++.h>
#define int long long

using namespace std;
vector<int> Dijkstra(int n , vector<int> cost, vector<vector<pair<int,int>>> adj)
{
    vector<int> dist(n, INT_MAX);//
    set<pair<int, int>> st;  //cost, node
    for(int i=0;i<n;i++)
    {
        dist[i]=cost[i];
        st.emplace(dist[i],i);
    }
    while(st.size())
    {
        auto [c,u] = *st.begin();
        st.erase(st.begin());
        if(dist[u] < c) continue;
        for(auto [v,w] : adj[u]){
            int new_d = dist[u] + w;
            if(dist[v] > new_d)
            {
                st.erase({dist[v], v});
                dist[v] = new_d;
                st.emplace(make_pair(new_d,v));
            }

        }
    }
    return dist;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        w*=2;
        u--, v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> cost(n);
    for(int i=0;i<n;i++){cin >> cost[i];}
    vector<int> dis = Dijkstra(n, cost, adj);

    for(int i=0;i<n;i++) {
        cout<<dis[i]<<" ";
    }


}