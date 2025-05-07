#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e25

int main()
{
    unordered_multiset<int> set;
    int n, d, result = 0;
    cin >> n >> d;
    int arr[n];

    for (auto &val : arr)
    {
        cin >> val;
    }

    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }

    for (auto it = set.begin(); it != set.end(); it++)
    {

        if (set.count(*it + d) && set.count(*it + d * 2))
        {
            result++;
        }
    }

    cout << result << endl;
}
