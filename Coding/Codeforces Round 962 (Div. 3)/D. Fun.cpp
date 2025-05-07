#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
#define line "\n"
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
// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; a * b <= n; b++)
            {
                int ub = min((n - a * b) / (a + b), x - a - b);
                if (ub >= 1)
                    count += ub;
            }
        }
        cout << count << line;
    }
}