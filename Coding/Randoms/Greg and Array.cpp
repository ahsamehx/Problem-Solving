#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e25
int N = 1e5 + 9;
int main()
{
    ll n, m, k, x, y;
    cin >> n >> m >> k;

    ll arr[N] = {0};
    pair<int, pair<ll, ll>> range[N];
    ll queries[m + 2] = {0}; // check
    ll final[n + 1] = {0};
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < m; i++) // input the operations
    {
        cin >> range[i].second.first >> range[i].second.second >> range[i].first;
    }

    while (k--)
    {
        cin >> x >> y;
        x--;
        queries[x]++;
        queries[y]--;
    }
    for (int i = 1; i < m; i++)
    {
        queries[i] += queries[i - 1];
    }

    for (int i = 0; i < m; i++)
    {
        queries[i] *= range[i].first;
        final[range[i].second.first - 1] += queries[i];
        final[range[i].second.second] -= queries[i];
    }

    for (int i = 1; i < n; i++)
    {
        final[i] += final[i - 1];
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] + final[i] << " ";
    cout << endl;
}