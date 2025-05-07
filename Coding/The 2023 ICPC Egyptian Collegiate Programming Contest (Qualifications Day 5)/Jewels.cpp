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
int res, n;
int temp;
char x;
void solve(int intial, string s)
{
    bool flag = true;
    for (int i = intial; i < n; i++)
    {
        if (s[i] == (i + 1 < n ? s[i + 1] : 2) && flag)
        {
            temp = i + 1;
            x = s[i];
            flag = false;
        }
        if (s[i] != x && !(flag))
        {
            s[temp] = s[i];
            s[i] = x;
            res += i - temp;
            solve(temp, s);
        }
    }
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        res = 0;
        cout << "-----------------------------------" << endl;
        int c1 = 0, c0 = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                c1++;
            else
                c0++;
        }
        if (!(c0 == c1 + 1 || c1 == c0 + 1 || c0 == c1))
        {
            cout << -1 << endl;
            break;
        }
        solve(0, s);
        cout << res << endl;
    }
}