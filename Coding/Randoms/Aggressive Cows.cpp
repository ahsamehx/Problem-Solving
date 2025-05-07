#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/
int n, c;
bool check(int mid, int arr[])
{
    int temp = c - 1, last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= mid)
        {
            temp--;
            last = arr[i];
        }
        if (temp <= 0)
            return true;
    }

    return false;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        int arr[n];
        for (auto &val : arr)
            cin >> val;
        sort(arr, arr + n);
        int left = 0, right = 1e3, res = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, arr))
            {
                left = mid + 1;
                res = mid;
            }
            else
                right = mid - 1;
        }
        cout << res << endl;
    }
}
