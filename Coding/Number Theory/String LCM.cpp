#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e6 + 20;
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
    Ahmed int t;
    cin >> t;
    while (t--)
    {
        string s = "", t = "";
        cin >> s >> t;
        int LCM = lcm(s.size(), t.size());
        string s_repeat, t_repeat;

        for (int i = 0; i < LCM / s.size(); i++)
            s_repeat += s;
        for (int i = 0; i < LCM / t.size(); i++)
            t_repeat += t;
        if(s_repeat == t_repeat)
            cout << s_repeat << endl;
        else 
            cout << -1 << endl;
    }
}
