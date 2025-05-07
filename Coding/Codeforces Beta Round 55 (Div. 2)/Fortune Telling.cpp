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
    int arr[n];
    for (auto&val: arr)
        cin >> val;

    int sum = 0; 
    for (auto val:arr)
        sum+=val;

    int result = 0;
    if (sum % 2 == 1) result = sum;
    for(int i = 0; i < n; i++)
    {
        int temp = sum; 
        temp -= arr[i];
        if(temp % 2 == 1 && temp > result) 
            result = temp;
    }

    cout << result << endl;
}