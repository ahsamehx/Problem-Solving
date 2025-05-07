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
    cin >> n;
    int freq[1001] = {0};
    for (int i = 2; i <= n; i++)
    {
        int temp = i;
        for (int j = 2; j <= temp; j++)
        {
            while (temp % j == 0)
            {
                temp /= j;
                freq[j]++;
            }
        }
    }
    int res = 1;
    for (int i = 0; i < 1001; i++)
    {
        res = mul(res, freq[i] + 1, mod);
    }

    cout << res << endl;
}