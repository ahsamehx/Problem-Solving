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
    Ahmed int n;
    cin >> n;
    int cnt = 0;
    int arr[n];
    for (auto val : arr)
        cin >> val;

    vector<int> v; // gaps nuts
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            v.emplace_back(i);
    }
    if (v.size() == 0)
        cout << 0 << endl, exit;
    if (v.size() == 1)
        cout << 1 << endl, exit;
    else
    {

        for (int i = 1; i < v.size(); i++)
        {
            int gap = v.at(i) - v.at(i - 1);
            res *= gap;
        }
        cout << res << endl;
    }
}
