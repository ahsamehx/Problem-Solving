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

signed main ()
{
    int n, x, h, m, s;
    cin >> n >> x >> h >> m >> s;
    int res = n - (h * 60 * 60 + m * 60 + s) * x;
    cout << (res > 0? res : 0) << endl;
}