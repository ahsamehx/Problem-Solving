#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 5;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    int t; 
    cin >> t ;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int count = 0;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '?')
            {
                if (count < t.length())
                    res+= t[count];
                else 
                    res+= 'a';

                count++;
                continue;;
            }
            if (s[i] == t[count])
            {
                count++;
            }
            res+= s[i];
        }
        if (count >= t.length())
            cout << "YES" << endl << res << endl;
        else 
            cout << "NO" << endl;
    }
    
}