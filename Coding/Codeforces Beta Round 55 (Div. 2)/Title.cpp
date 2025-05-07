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

// signed main()
// {
//     int k;
//     cin >> k;
//     string s;
//     cin >> s;
//     string temp = "";

//     if (s.length() < 2 * k - 1)
//         cout << "IMPOSSIBLE" << endl, exit(0);

//     if ((s.length() - (2 * k - 1)) % 2 == 0 || s.length() == (2 * k - 1))
//     {
//         int cnt = (s.length() - (2 * k - 1)) / 2;
//         while (cnt--)
//             temp += char(97);

//         for (int i = 97; i < 97 + k; i++)
//             temp += char(i);

//         cnt = (s.length() - (2 * k - 1)) / 2;

//         for (int i = 97 + k - 2; i >= 97; i--)
//             temp += char(i);

//         while (cnt--)
//             temp += char(97);
//     }
//     else if ((s.length() - (2 * k - 1)) % 2 != 0)
//     {
//         int cnt = (s.length() - (2 * k - 1)) / 2;

//         while (cnt--)
//             temp += char(97);

//         for (int i = 97; i < 97 + k; i++)
//             temp += char(i);

//         cnt = (s.length() - (2 * k - 1)) / 2;
//         temp += char(97 + k - 1);
//         for (int i = 97 + k - 2; i >= 97; i--)
//             temp += char(i);

//         while (cnt--)
//             temp += char(97);
//     }
//     int l = 0, r = s.length() - 1;
//     int buff = 0;
//     bool check[k];
//     while (l <= r)
//     {
//         // cout << s[l] << " " << s[r] << endl;
//         if ((s[l] != s[r] && s[l] != '?') && s[r] != '?')
//             cout << "IMPOSSIBLE" << endl, exit(0);
//         if (s[l] == s[r] && s[l] == '?')
//             buff++;
//         l++, r--;
//         if (s[l] != '?')
//             check[s[l] - 'a'] = true;
//         if (s[r] != '?')
//             check[s[r] - 'a'] = true;
//     }

//     for (auto val : check)
//     {

//         if (val == false)
//         {
//             buff--;
//             if (buff == -1)
//                 cout << "IMPOSSIBLE" << endl, exit(0);
//         }
//     }
//     cout << temp << endl;
// }

signed main ()
{
    
    cout << __gcd(100, -1000);
}



