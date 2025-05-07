#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e5 + 20;
#define Ahmed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
long long mul(long long x, long long y, const long long &mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long &mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int res = 0;
        
        
        while (n%2 == 0)
        {
            res = 2;
            n/= 2;
        }
        
        for (int i = 3; i * i <= n; i+= 2)
        {
            while(n % i == 0)
            {
                res = i;
                n/= i;
            }
            if(n == 1)
                break;
        }
        
        if(n > 1) res = n;

        cout << res << endl;
    }
}
