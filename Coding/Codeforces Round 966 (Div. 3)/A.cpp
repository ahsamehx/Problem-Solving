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

signed main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        string s; 
        cin >> s;
        if (s.size() == 1 || s.size() == 2)
            cout << "NO" << endl;

        else if (s.size() == 3)
        {
            if (s[0] == '1'  && s[1] == '0' && s[2] - '0' >= 2)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
        else 
        {
        if (s[0] == '1'  && s[1] == '0' && (s[2]+s[3]) - '0' > 2 && s[2] - '0' > 0)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        }
    }
}