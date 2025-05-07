#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e6 + 5;
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
    Ahmed bool sieve[N + 2];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int result = 0;

        for (int i = 0; i <= n; i++)
        {
            if (sieve[i])
                result+= i;
        }
        cout << result << endl;
    }
}