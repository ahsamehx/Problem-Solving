#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e6

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0, right = 0;
    int sum = 0;
    int result = inf;
    bool flag = true;
    while (right < n)
    {
        while (right < n && sum < m)
        {
            sum += arr[right];
            right++;
        }
        if (sum < m)
        {
            flag = false;
            break;
        }
        while (sum - arr[left] >= m)
        {
            sum -= arr[left];
            left++;
        }
        result = min(result, right - left);
        sum -= arr[left];
        left++;
    }
    (flag) ? cout << result << endl : cout << "IMPOSSIBLE" << endl;
}