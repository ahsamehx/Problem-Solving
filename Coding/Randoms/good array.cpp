#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    const int M = 1e6 + 1;
    const int N = 2e5 + 5;
    int freq[M];
    int n;
    cin >> n;
    int arr[N];
    int secondmx = -1;
    __int128 sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
        sum += arr[i];
    }

    int mx = *max_element(arr, arr + n);

    if (freq[mx] == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mx)
                continue;
            secondmx = max(secondmx, arr[i]);
        }
    }
    else
        secondmx = mx;

    for (int i = 0; i < n; i++)
    {
        int RangeMx = -1;
        if (arr[i] == mx)
            RangeMx = secondmx;
        else
            RangeMx = mx;
        if (RangeMx == sum - RangeMx - arr[i])
            v.emplace_back(i + 1);
    }
    cout << v.size() << endl;
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}