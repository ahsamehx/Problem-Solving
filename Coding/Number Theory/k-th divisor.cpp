#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

vector <int> v;

int solve (int n, int k)
{
    v.push_back(1);
    for (int i = 2; i * i <= n; i++)
    {
        if (n%i == 0)
        {
            v.push_back(i);
            if(n/i != i)
                v.push_back(n/i);
        }
    }
    v.push_back(n);

    sort (v.begin(), v.end());

    if (k > v.size())
        return -1;
    else
        return v[k-1];
}

signed main()
{
    int n, k;
    cin >> n >> k;
    
    int res = solve(n, k);

    cout << res << endl;
}