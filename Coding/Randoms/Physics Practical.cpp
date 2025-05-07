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
        cin >> val;
    sort(arr, arr + n);
    int left = 0, right = n - 1, result = 0;
    while (arr[right] > 2 * arr[left])
    {
        if (arr[right] - arr[right - 1] > arr[left + 1] - arr[left])
            right--;
        else 
            left++;
        result++;
    }
    cout << result << endl;
}