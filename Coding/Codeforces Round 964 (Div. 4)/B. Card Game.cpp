#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 5;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    Ahmed
    int t; 
    cin >> t ;
    while (t--)
    {
    int res = 0;
    int a1, a2, b1, b2;
    cin >> a1>> a2 >> b1 >> b2;
    if (a1 > b1 && a2 > b2)
        res++;
    if (a2 > b1 && a1 > b2)
        res++;
    if (a2 > b2 && a1 > b1)
        res++;
    if (a1 > b2 && a2 > b1)
        res++;
    cout << res << endl;
    }
    
}