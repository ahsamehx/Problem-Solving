#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
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
    Ahmed int n;
    while (cin >> n && n)
    {
        for (int i = 2; i * i <= n; i++)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            if (cnt)
                cout << i << "^" << cnt << " ";
        }
        if (n - 1)
            cout << n << "^1";

        cout << endl;
    }
}