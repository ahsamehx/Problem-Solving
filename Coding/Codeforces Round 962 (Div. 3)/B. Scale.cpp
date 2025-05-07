#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool isWhole(int x)
{
    long double y = sqrt((long double)x);
    if (y != sqrt(x))
        return false;
    return true;
}
// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        vector <string> v;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            string s, res ="";
            cin >> s;
            if (i % k != 0)
                continue;
            for (int j = 0; j < n; j= j+k)
            {
                char c = s[j];
                res += c;
            }
            v.push_back(res);
        }
        for (auto val:v)
            cout << val << endl;        
    }
}