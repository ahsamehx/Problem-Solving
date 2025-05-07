#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/
int have[3], price[3], need[3] = {0}, money; // BSC
bool check(int mid, int n)
{
    int temp = money;
    for (int i = 0; i < 3; i++)
    {
        int needed = need[i] * mid;
        if (needed > have[i])
        {
            temp -= (needed - have[i]) * price[i];
        }
        if (temp < 0)
            return false;
    }
    return true;
}

signed main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            need[0]++;
        else if (s[i] == 'S')
            need[1]++;
        else
            need[2]++;
    }
    for (auto &val : have)
        cin >> val;
    for (auto &val : price)
        cin >> val;
    cin >> money;

    int left = 0, right = 1e12 + 120, res = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, n))
        {
            res = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << res << endl;
}