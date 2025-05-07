#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
#define Ahmed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
long long mul(long long x, long long y, const long long &mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long &mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

signed main()
{
    int a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    set<int> dv_a;
    set<int> dv_b;

    for (int i = 1; i * i <= max(a, b); i++)
    {
        if (a % i == 0)
        {
            dv_a.insert(i);
            dv_a.insert(a/i);
        }
        if (b % i == 0)
        {
            dv_b.insert(i);
            dv_b.insert(b/i);
        }
    }
    dv_a.insert(a);
    dv_b.insert(b);
    vector<int> dv;

    for (auto val : dv_a)
    {
        if (dv_b.count(val))
            dv.emplace_back(val);
    }

    while (q--)
    {
        int low, high;
        cin >> low >> high;
        int res = -1;
        for (auto val : dv)
        {
            if (val > high)
                break;
            if (val >= low)
                res = val;
        }

        cout << res << endl;
    }
}