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
    bool prime[N];
    memset(prime, true, sizeof(prime));
    vector<int> v;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                prime[j] = false;
            
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if(prime[i])
            v.push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        cout << v.at(n) << endl;
    }
}
