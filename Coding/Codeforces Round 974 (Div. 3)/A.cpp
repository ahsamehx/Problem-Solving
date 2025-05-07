#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 5;
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
    Ahmed int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int res;
        for (int i = 0; i < n; i++)
        {
            int total = 0;
            res = 0;
            int x;
            cin >> x;
            if (x >= k)
                total += x;
            if(x == 0 && total > 0)
                res++;
        }
        cout << res << endl;
    }
}