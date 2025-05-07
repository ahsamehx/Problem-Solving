#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool isWhole(int x)
{
    long double y = sqrt((long double)x);
    if (y != sqrt(x))
        return false;
    return true;
}
/*======================================ahsamehx===========================================*/
int arr[N];
signed main()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        arr[l]++;
        arr[r + 1]--;
    }

    int prefix[n + 1];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    int result = 0;
    int l = -1, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] == 0 && (i ? prefix[i - 1] : 1))
        {
            l = r = i;
        }

        if (prefix[i] == 0 && (i == n - 1 ? 1 : prefix[i + 1] != 0))
            r = i;
        result = max(result, r - l);
    }
    cout << (l == -1 ? 0 : result + 1) << endl;
}