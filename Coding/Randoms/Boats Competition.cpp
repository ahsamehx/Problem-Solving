#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (auto &val : arr)
            cin >> val;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int temp;
            for (int j = i + 1; j < n - 1; j++)
            {
                if((arr[i]+arr[j]) == temp)
                    break;
                mp[(arr[i]+arr[j])]++;
                int temp = arr[i]+arr[j];
            }
        }
        int result = 0;
        for(auto it:mp)
        {
            result = max(result, it.second);
        }
        cout << result << endl;
    }
}