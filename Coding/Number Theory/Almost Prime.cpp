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
    int n; 
    cin >> n; 
    bool prime[n+1];
    int arr[n+1] = {0};
    
    memset(prime, true, sizeof(prime));
    for (int i = 2; i <=n; i++)
    {
        if (prime[i])
        {
            for(int j = i + i; j <= n; j += i)
            {
                arr[j]++;
                prime[j] = false;
            }
        }
    }
    
    int cnt = 0; 
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == 2)
            cnt++;
    }
    
    cout << cnt << endl;
}