#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6+5;
const int mod = 1073741824;
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

    int sieve[N] = {0};
    sieve[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        for(int j = i; j <= N; j+= i)
            sieve[j]++;
    }
    
    int a, b, c;
    cin >> a >> b >> c;

    int result = 0;

    for (int i = 1; i <= a + 1; i++)
    {
        for (int j = 1; j <= b + 1; j++)
        {
            for (int k = 1; k <= c + 1; k++)
            {
                result += sieve[i*j*k] % mod;
            }
        }
    }
    cout << result << endl;
}