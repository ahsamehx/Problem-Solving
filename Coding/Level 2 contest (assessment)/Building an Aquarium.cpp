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
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int  i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int l = 1, r =  2e9+1;
        while (l < r) {
            int mid = l + (r - l +1)/2;
            int total = 0;
            for (int i = 0; i < n; i++) {
                total+=max(mid - arr[i], 0ll);
            }
            if(total <= x)
                l = mid;
            else r = mid -1;
        }
        cout << l << endl;
    }
}