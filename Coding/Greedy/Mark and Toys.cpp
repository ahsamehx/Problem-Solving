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
    int arr[n];
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    sort (arr, arr+n);
    
    int sum = 0; 
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        sum+= arr[i];
        if(sum <= m)
            res++;
        else 
            break;
    }

    cout << res << endl;
}