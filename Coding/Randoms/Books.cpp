#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9

int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (auto &val : arr)
        cin >> val;
    //sort(arr, arr + n);
    int sum = 0, left = 0, right = 0, result = 0;
    while (right < n)
    {
        sum += arr[right];
        while (sum > t)
        {
            sum -= arr[left];
            left++;
        }
        result = max(result, right - left + 1);
        right++;
    }
    cout << result << endl;
}
