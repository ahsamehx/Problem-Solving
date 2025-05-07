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
    int t;
    cin >> t;
    while (t--)
    {
        int n, result = 0;
        int freq[28] = {0};
        string s;
        cin >> n;
        cin >> s;
        for (int i = 1; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < 28; i++)
        {
            int x = freq[i];
            result += (x * (x - 1)) / 2;
        }
        cout << endl;
        result += n - 1;
        cout << result << endl;
    }
}