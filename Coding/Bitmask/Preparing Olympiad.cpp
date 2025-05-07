#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
#define line "\n"
const int N = 2e5 + 20;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int arr[n];
    int res = 0;
    for (auto& val: arr)
        cin >> val;
    
    for (int i = 0; i < (1 << n); i++)
    {
        int mn = inf, total = 0, mx = 0;
        for (int j = 0; j < n; j++)
        {
            if( i & (1 << j))
            {
                mn = min(mn, arr[j]);
                mx = max(mx, arr[j]);
                total += arr[j];
            }
        }
        if (mn >= l && mx <= r && (mx - mn) >= x)
            res++;
    } 

    cout << res << line;
}