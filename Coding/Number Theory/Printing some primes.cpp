#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e8;
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

    vector <bool> sieve (N, true);
    sieve[0] = sieve[1] = false;
    vector<int> v;
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (sieve[i])
            v.emplace_back(i);
    }

    for (int i = 0; i < v.size(); i += 100)
    {
        cout << v.at(i) << endl;
    }
}