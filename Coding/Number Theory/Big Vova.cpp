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
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int mx = -1, ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mx)
            {
                mx = arr[i];
                ind = i; // index for the max element
            }
        }
        arr[ind] = 0; // set the index of mx element to 0
        // try every element with mx and find the maximum GCD then print the number then reset the element to 0
        cout << mx << " ";
        for (int i = 0; i < n - 1; i++)
        {
            int gcd = -1;
            int index = -1; // index for mx gcd
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == 0)
                    continue;
                if (__gcd(mx, arr[j]) > gcd || ((__gcd(mx, arr[j]) == gcd )&& (arr[j] > arr[index])))
                {
                    gcd = __gcd(mx, arr[j]);
                    index = j;
                }
            }
            cout << arr[index] << " ";
            arr[index] = 0;
        }
        cout << endl;
    }
}