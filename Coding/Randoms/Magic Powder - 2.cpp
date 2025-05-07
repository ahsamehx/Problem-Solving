#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/   
int n, k, a[N], b[N];

bool check(int mid)
{
    int temp = k;
    for (int i = 0; i < n; i++)
    {
        int need = mid * a[i];
        if (need > b[i])
        {
            temp -= need - b[i];
            if (temp < 0)
                return false;
        }
    }

    return true;
}

signed main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int left = 0, right = 2e9, res = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid))
        {
            res = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << res << endl;
}