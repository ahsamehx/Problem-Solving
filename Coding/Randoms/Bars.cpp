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
int n, x;
int arr[N];
bool solve(int idx, int temp)
{
    if (temp == x)
        return true;

    if (idx == n || temp >x)
        return false;

    if (solve(idx+1, temp+(arr[idx])))
        return true;

    return solve(idx+1, temp);

}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        cout << (solve(0, 0)? "YES" : "NO") << endl;
    }
}