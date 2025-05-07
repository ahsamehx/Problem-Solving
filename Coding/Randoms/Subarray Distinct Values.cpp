#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/

signed main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (auto &val : arr)
        cin >> val;
    map<int, int> mp;
    int right = 0, left = 0, res = 0;

    while (right < n)
    {
        mp[(arr[right])]++;
        while (mp.size() > k)
        {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0 )
                mp.erase(arr[left]);

            left++;
        }
        res += right - left + 1;
        right++;
    }
    cout << res << endl;
}