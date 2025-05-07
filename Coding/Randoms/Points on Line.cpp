#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9

ll cal(ll r)
{
    return r * (r - 1) / 2;
}

signed main()
{
    ll n, d;
    cin >> n >> d;
    ll arr[n];
    for (auto &val : arr)
        cin >> val;

    ll left = 0, right = 2;
    ll res = 0;
    while (right < n)
    {
        if (arr[right] - arr[left] <= d)
        {
            right++;
            continue;
        }
        else
        {
            ll num = right - left;
            num--;
            res += cal(num);
            left++;
        }
    }
    while (left < n && arr[n - 1] - arr[left] <= d)
    {
        ll num = right - left;
        num--;
        res += cal(num);
        left++;
    }
    cout << res << endl;
}