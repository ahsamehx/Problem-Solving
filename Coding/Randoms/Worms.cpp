#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9

signed main()
{
    int n, m;
    cin >> n;
    int prefix[n];
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> prefix[i];
        (i) ? prefix[i] += prefix[i - 1] : prefix[i];
    }
    cin >> m;
    int arr[m];
    for (auto&val:arr)
        cin >> val;
    
    for (int i = 0; i < m; i++)
    {
        int left = 0, right = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (prefix[mid] > arr[i] )
                left = mid + 1;
            else
                right = mid - 1;
        }
        v.emplace_back(left);
    }
    for (auto& val:v)
        cout << val << endl;

}