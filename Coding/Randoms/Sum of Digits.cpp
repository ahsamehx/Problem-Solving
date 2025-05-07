#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 20;
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
    int n; 
    cin >> n; 
    string s = to_string(n);
    int size = s.size();
    int sum = 0;
    int cnt = 0;
    while (true)
    {
        int x; 
        x = n%10;
        n /= 10;
        sum+= x;
        cnt++;
        if (x == 0) n = sum, sum = 0;
        if(sum / 10 == 0 && cnt >= size) break;
    }

    cout << sum << endl;
    
}
