#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/
bool isPrime(int x)
{
    if (x <= 1) return false;
    for (int i = 2; i < x/2; i ++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

bool isWhole(int x)
{
    long double y = sqrt((long double)x);
    if(y != sqrt(x))
        return false;
    return true;
}

signed main()
{
    int n, x;
    cin >> n >> x;
    if (x > n)
        cout << 0 << endl;
    else if (x == 1)
        cout << 1 << endl;
    else if (isPrime(x))
        cout << 2 << endl;
    else if (isWhole(x))
        cout << 3 << endl;
    else 
        cout << 4 << endl;
}