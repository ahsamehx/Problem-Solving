#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e12
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/
int n;
long double k;
bool check(int mid, int arr[])
{
    int sum = mid;
    for (int i = 1; i < n; i++)
    {
        sum += arr[i - 1];
        if ((long double)arr[i] / sum > k / 100)
            return false;
    }
    return true;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int arr[n];
        for (auto &val : arr)
            cin >> val;

        int left = 0, right = inf;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, arr))
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout << left << endl;
    }
}