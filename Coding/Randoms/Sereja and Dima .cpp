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
    int left = 0, right = n - 1;
    bool flag = true; // true when odd
    int result1 = 0, result2 = 0;

    while (n--)
    {
        if (arr[left] > arr[right])
        {
            (flag) ? result1 += arr[left] : result2 += arr[left];
            left++;
        }
        else 
        {
           (flag) ? result1 += arr[right] : result2 += arr[right];
            right--; 
        }
        flag = !flag;
    }
    cout << result1 << " " << result2 << endl;
}