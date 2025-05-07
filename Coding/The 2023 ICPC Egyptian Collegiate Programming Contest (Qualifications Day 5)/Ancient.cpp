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
    set<int> s;
    while (t--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int res = 0;
        res += (n % 2 == 0 ? n / 2 : n / 2 + 1) * x; // beach cost
        res += (n % 3 == 0 ? n / 3 : n / 3 + 1) * y; // pool cost
        res += n * z;
        s.insert(res);
    }
    cout << *s.begin() << endl;
    
}