#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e6

int main()
{
    int x, n;
    cin >> n >> x;
    int arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }

    int right = 0, left = 0;
    int sum = 0, result = inf;
    while (right < n)
    {
        while (sum < x && right < n)
        {
            sum += arr[right];
            right++;
        }
        if (sum >= x)
            result = min(result, right - left);
        sum -= arr[left];
        left++;
    }
    (result == inf) ? cout << -1 : cout << result;
    cout << endl;
}