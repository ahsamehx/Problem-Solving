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
// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int res = 0; 
        res += n/4;
        res+= (n%4) /2;
        cout << res << "\n";
    }
}