#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/
int n, k;
bool check(int mid, int arr[])
{
    int ops = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (mid > arr[i])
            ops += mid - arr[i];
        if (k < ops)
            return false;
    }
    return true;
}
signed main()
{
    cin >> n >> k;
    int arr[n];
    for (auto &val : arr)
        cin >> val;

    int left = arr[n / 2], right = 1e10;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(mid, arr))
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << right << endl;
}