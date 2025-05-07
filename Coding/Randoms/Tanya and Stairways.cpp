#include <bits/stdc++.h>
using namespace std;

int main()
{
    int stairways = 0, n;
    cin >> n;
    int arr[n];
    vector<int> v;
    for (auto &val : arr)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++) // 1 2 3 1 2 3 4
    {
        if (arr[i] == 1)
        {
            stairways++;
            if (i>0) v.push_back(arr[i-1]);
        }
    }
    v.push_back(arr[n-1]);
    cout << stairways << endl;
    for (auto &val : v)
    {
        cout << val << " ";
    }
}