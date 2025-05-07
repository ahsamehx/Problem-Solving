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
int power(int b, int p)
{
    if (p == 0)
        return 1;

    int result = 1;

    while (p > 0)
    {
        if (p % 2 == 0)
        {
            b *= b;
            p /= 2;
        }
        else
        {
            result *= b;
            p--;
        }
    }
    return result;
}

signed main()
{
    Ahmed int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int start = n - k + 1;
        int end = n;
        int even;
        if (start % 2 == 0)
            start = start;
        else
            start = start + 1;
        
        if()
        int odd;

        cout << (even > odd ? "Yes" : "No") << endl;
    }
}