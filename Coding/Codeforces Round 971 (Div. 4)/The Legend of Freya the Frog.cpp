#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 20;
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
    Ahmed 
    int t; 
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int xx = 0 , yy = 0;
        bool flag = true; // true is facing x
        int res = 0;
        while (true)
        {
            if(flag)
            {
                xx+= k;
                res++;
            }
            if (!(flag))
            {
                yy+= k;
                res++;
            }
            if(xx >= x && yy >= y)
                break;
            flag = !flag;
        }
        cout << res << endl;
    }
}
