#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e5 + 20;
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
    int n, k;
    cin >> n >> k;
    vector<int> factors;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.emplace_back(i);
            n/= i;
        }
    }
    
    if(factors.size() > k)
    {
        for(int i = 0; i < k - 1; i++)
        {
            cout << factors.at(i) << " ";
        }
        int prod = 1; 
        for (int i = k-1; i < factors.size(); i++)
            prod*= factors.at(i);
        cout << prod << endl;
    }
    else if (factors.size() == k)
    {
        for (auto val : factors)
            cout << val << " ";
    }
    else 
    {
        cout << -1 << endl;
    }
    
}

