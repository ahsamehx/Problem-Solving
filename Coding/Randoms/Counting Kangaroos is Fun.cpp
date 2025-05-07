#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e6

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }
    sort(arr, arr + n);
    int right = (n + 1) / 2, left = 0;
    int result = 0;
    while (right < n)
    {
        while (right < n && arr[left] * 2 <= arr[right])
        {
            result++;
            right++;
            left++;
        }
        right++;
    }
    cout << n - result << endl;
}