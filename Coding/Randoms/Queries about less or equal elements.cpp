#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9

signed main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    vector<int> v;
    for (auto &val : arr1)
        cin >> val;
    for (auto &val : arr2)
        cin >> val;

    sort(arr1, arr1 + n);

    for (int i = 0; i < m; i++)
    {
        int left = 0, right = n - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (arr1[mid] <= arr2[i])
            {
                left = mid+1;
            }
            else
                right = mid;
        }
        v.emplace_back(left);
    }
    for (auto val : v)
        cout << val << " ";
}