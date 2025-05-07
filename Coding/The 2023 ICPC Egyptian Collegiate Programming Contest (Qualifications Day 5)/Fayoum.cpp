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

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &val : arr)
        cin >> val;
    int prefix[n + 1];
    for (int i = 0; i < n; i++)
    {
        prefix[i]++;
        prefix[(i + arr[i] >= n ? n : i + arr[i])]--;
    }
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i] + prefix[i - 1];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, prefix[i]);
    }
    cout << res << endl;
}