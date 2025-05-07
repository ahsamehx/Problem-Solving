#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 20;

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
        int n, k = 0;
        cin >> n;
        bool flag = true;
        int arr1[n];
        int arr2[n];
        int array[n + 1];
        array[n] = 0;
        bool range_end = false;
        bool first_dif = false;
        for (auto &val : arr1)
            cin >> val;
        for (auto &val : arr2)
            cin >> val;
        
        for (int i = 0; i < n; i++)
        {
            array[i] = arr2[i] - arr1[i];
        }
        int flip = 0;
        for (int i = 0; i < n; i++)
        {
            if(array[i]!=0 && !first_dif) {
                first_dif = true;
                k = array[i];
            }
            if(array[i] < 0 || (array[i] != k && array[i]!= 0)) {
                flip = 4;
                break;
            }
            if(array[i] != array[i+1]) flip++;
        }
        cout << ((flip <= 2) ? "YES" : "NO") << endl;
    }
}
