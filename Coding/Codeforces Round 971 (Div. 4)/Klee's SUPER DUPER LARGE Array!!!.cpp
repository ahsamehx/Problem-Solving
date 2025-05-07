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
        int n, k;
        cin >> n >> k;
        int arr[n/2];
        int prefix[n/2];
        int suffix[n/2];
        for (int i = 0; i < n/2; i++)
        {
            arr[i] = i + k;
            (i) ? prefix[i] = arr[i] + prefix[i-1] : arr[i];
        }

        reverse(arr, arr + n/2);
        for (int i = 0; i < n/2; i++)
        {
            (i) ? suffix[i] = arr[i] + suffix[i-1] : arr[i];
        }
        reverse(suffix, suffix + n/2);

        int res = inf;
        for(int i = n)
    }
}
