#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    Ahmed
    int n, m;
    cin >> n >> m;
    deque <int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    while(m--)
    {
        int x = v.front();
        v.pop_front();
        v.push_back(x);
    }

    for (auto&val:v)
        cout << val uuu<< " ";
    cout << endl;
}