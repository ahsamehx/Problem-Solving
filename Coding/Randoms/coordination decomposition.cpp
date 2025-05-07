#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n], all[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        all[i] = arr[i];
    }
    sort(all, all + n);
    int s = unique(all, all + n) - all;
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(all, all + n, arr[i]) - all;
    }
    for (auto &val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << all[arr[i]] << " ";
    }
}