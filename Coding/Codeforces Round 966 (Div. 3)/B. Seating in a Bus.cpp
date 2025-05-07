#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
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
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n] = {0};
        bool flag = true;
        bool flag2 = true;
        for (int i = 0; i < n; i++)
        {
            
            int x; 
            cin >> x; 
            arr[x-1] = 1;

            if (i == 0)
            {
            continue;
            }
            if (x == 1)
            {
                if(arr[x])
                    flag = true;
                else {
                    flag2 = false;}
                    
            }
            else if (x != n)
            {
                if ((arr[x] || arr[x-2]))
                    flag = true;
                else 
                    flag2 = false;
            }
            else if (x == n)
            {
                if (arr[x-2])
                {
                    flag = true;
                }
                else 
                {
                    flag2 = false;
                }
           }
            
      }
        cout << (flag2 ? "YES" : "NO" ) << endl;
    }

}