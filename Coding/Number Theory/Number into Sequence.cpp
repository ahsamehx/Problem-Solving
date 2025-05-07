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
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> factors;
        for (int i = 2; i <= sqrt(n); i++)
        {
            while (n % i == 0)
            {
                factors.push_back(i);
                n /= i;
            }
        }
        if (n != 1)
            factors.push_back(n);

        map<int, int> mp;
        for (auto &val : factors)
            mp[val]++;
        vector<pair<int, int>> freqs;
        for (auto &val : mp)
        {
            freqs.emplace_back(val.second, val.first);
        }
        sort(freqs.rbegin(), freqs.rend());
        vector<int> res;
        while (freqs.front().first > 1)
        {
            res.emplace_back(freqs.front().second);
            freqs.front().first--;
        }
        int mul = 1;
        for (auto &val : freqs)
        {
            while (val.first > 0)
                mul *= val.second, val.first--;
        }
        cout << res.size() + 1 << endl;
        for (auto &val : res)
            cout << val << " ";
        cout << mul << endl;
    }
}
