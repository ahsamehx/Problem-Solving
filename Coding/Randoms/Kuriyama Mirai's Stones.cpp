#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e25

int main()
{
    ll l, r, n, m;
    cin >> n;
    ll arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }
    ll prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    sort(arr, arr + n);
    ll prefix_sorted[n];
    prefix_sorted[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sorted[i] = prefix_sorted[i - 1] + arr[i];
    }

    cin >> m;
    char type;
    while (m--)
    {
        
        cin >> type;
        cin >> l >> r;
    
        if (type == '1')
        {
            if (l == 1)
                cout << prefix[r - 1] << endl;
            else 
                cout << prefix[r - 1] - prefix[l - 2] << endl;
        }
        else
        {
            if (l == 1)
                cout << prefix_sorted[r - 1] << endl;
            else 
                cout << prefix_sorted[r - 1] - prefix_sorted[l - 2] << endl;
        }

    }
}
