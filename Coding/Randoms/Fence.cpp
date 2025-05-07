#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e25

int main()
{
    int n, h, k;
    cin >> n >> k;
    int arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int temp = prefix[k-1];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if ((prefix[i + k - 1] - prefix[i-1]) < result)
            result = i +1;
    }
    cout << result << endl;
}