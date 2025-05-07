#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
bool can(int mid, int a[], int c[], int n, int h)
{
    // logic
    int damage = 0;
    for (int i = 0; i < n; i++)
    {
        damage += (1 + (mid - 1) / c[i]) * a[i];
        return (damage >= h);
    }
    return false;
}
signed main()
{
    int t, h, n;
    cin >> t;
    while (t--)
    {
        cin >> h >> n;
        int c[n], a[n];
        for (auto &val : a)
            cin >> val;
        for (auto &val : c)
            cin >> val;
        int right = 1e11, left = 0, res = 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (can(mid, a, c, n, h))
            {
                right = mid - 1;
                res = mid;
            }
            else
                left = mid + 1;
        }
        cout << res << endl;
    }
}