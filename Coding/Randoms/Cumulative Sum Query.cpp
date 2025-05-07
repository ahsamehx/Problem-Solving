#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e25

int main()
{
    int n, q, l, r;
    cin >> n;
    int arr[n];
    int prefix[n];

    for (auto &val : arr)
    {
        cin >> val;
    }
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    cin >> q;
    while (q--)
    {
        cin >> l >> r;

         if (l == 0)
        {
            cout << prefix[r] << endl;
        }
        else
        {
            cout << prefix[r] - prefix[l - 1] << endl;
        }
    }
}