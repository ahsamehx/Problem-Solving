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
    Ahmed
    int t; 
    cin >> t ;
    while (t--)
    {
        int l = 2, r = 999;
        while (l <= r)
        {
            int mid1 = l + (r - l)/3;
            int mid2 = r - (r - l)/3;
            int area;
            cout << "? " << mid1 << " " << mid2 << endl;
            cin >> area;
            if(area ==  (mid1+1) * (mid2+1))
            {
                r = mid1 -1;
            }
            else if (area == mid1 * (mid2 + 1))
            {
               r = mid2 - 1;
               l  = mid1 + 1;
            }
            else if (area == (mid1) * (mid2))
            {
                l = mid2+1;
            }
        }
        cout << "! " << l << endl;
    }

}