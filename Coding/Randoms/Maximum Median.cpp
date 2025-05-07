#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/

signed main()
{
    int n, k, res;
    cin >> n >> k;
    int arr[N];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    vector prefix(n, 0);
    for (int i = n / 2 + 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + (arr[i] - arr[i - 1]) * (i - n / 2);
    }

    if (k <= prefix[n / 2 + 1])
        res = arr[n / 2] + k;
    else if (k >= prefix[n - 1])
    {
        int temp = (k - prefix[n - 1]) / (n / 2 + 1);
        res = arr[n - 1] + temp;
    }
    else
    {
        int where;
        for (int i = n / 2 + 2; i < n - 1; i++)
        {
            if (k >= prefix[i])
                where = i;
            else
                break;
        }
        int odd = (where % 2 == 0) ? 0 : 1;
        int temp = (k - prefix[where]) / ((where / 2) + odd);
        res = arr[where] + temp;
    }
    cout << res << endl;
}