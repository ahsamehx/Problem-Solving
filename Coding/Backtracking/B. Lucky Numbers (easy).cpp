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

vector <int> v;
void lucky (int num, int fours, int sevens)
{
    if (num > 1e10) return;
    if (fours == sevens)
        v.push_back(num);

    lucky(num*10+4, fours+1, sevens);
    lucky(num*10+7, fours, sevens+1);
}
signed main()
{
    int n; 
    cin >> n;
    lucky(7, 0, 1);
    lucky(4, 1, 0);
    sort(v.begin(), v.end());
    cout << *lower_bound(v.begin(), v.end(), n) << endl;
}