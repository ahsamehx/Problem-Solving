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
int get_num_lenght(int x)
{
    int cnt =0;
    while (x)
    {
        x /= 3;
        cnt++;
    }
    return cnt;
}

signed main()
{
    Ahmed
    int t; 
    cin >> t; 
    int pref[N] = {0};
    for (int i = 0; i < N; i++)
    {
        int cnt = get_num_lenght(i);
        pref[i] = pref[i-1] + cnt;
    }
    while (t--)
    {
        
        int l, r; 
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] + get_num_lenght(l) << endl;
    }
}