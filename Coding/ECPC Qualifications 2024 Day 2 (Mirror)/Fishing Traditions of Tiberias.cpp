#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool isWhole(int x)
{
    long double y = sqrt((long double)x);
    if (y != sqrt(x))
        return false;
    return true;
}
/*======================================ahsamehx===========================================*/

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i < n + 1; i++)
        {
            int val;
            cin >> val;
            mp[val] = i;
        }
        cin >> q;
        int add = 0;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            add += x;
            if (mp.count(y))
            {
                cout << mp[y] + ((n - add) % n) << endl;
            }
            else
                cout << -1 << endl;
        }
    }
}