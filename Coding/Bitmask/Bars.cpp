#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e6 + 10;
#define Ahmed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    Ahmed
    int t; 
    cin >> t; 
    while (t--)
    {
        int target, n;
        cin >> target >> n;
        int arr[n];
        bool flag = false;
        for (auto&val:arr)
            cin >> val;
        
        for (int i = 0; i < (1 << n); i++)
        {
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    sum += arr[j];
            }
            if (sum == target)
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}