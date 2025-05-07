#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e25

int main()
{
    int n, k;
    cin >> n >> k;
    int therom[n];
    int minutes[n];
    int min_awake = 0;
    for (auto &val : therom)
        cin >> val;
    for (int i = 0; i < n; i++)
    {
        cin >> minutes[i];
        if (minutes[i])
        {
            min_awake += therom[i];
            therom[i] = 0;
        }
    }

    int prefix[n] = {0};
    prefix[0] = therom[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + therom[i];
    }
    int mx = 0;
    for (int i = 0; i < n - k; i++)
    {
        mx = max(mx, (i) ? prefix[i + k - 1] - prefix[i - 1] : prefix[i + k - 1]);
    }

    int result = min_awake + mx;
    cout << result << endl;
}