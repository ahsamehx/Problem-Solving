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
        int n;
        cin >> n;
        int x = 0;
        vector<int> v(n);
        bool flag = false;

        for (auto &val : v)
        {
            cin >> val;
        }
        if (v.at(0) % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        else
        {
            flag = true;
            for (int i = 0; i < n; i++)
            {
                int ind = i + 2;
                if (v.at(i) % ind != 0)
                {
                    x++;
                }
                else
                {
                    for (int j = 1; j <= x; j++)
                    {
                        if (v.at(i) % (ind - j) != 0)
                        {
                            x++;
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }
}
