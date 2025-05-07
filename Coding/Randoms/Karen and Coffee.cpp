#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e25

int main()
{

    int n, k, q, l, r, mx = 0;
    cin >> n >> k >> q;
    int freq[200009] = {0};
    int prefix[200009] = {0};
    int result[200009] = {0};
    while (n--)
    {
        cin >> l >> r;
        freq[l]++;
        if (r + 1 < 200009)
            freq[r + 1]--;
    }

    prefix[0] = freq[0];

    for (int i = 1; i < 200009; i++)
    {
        prefix[i] = freq[i] + prefix[i - 1];
    }

    for (int i = 0; i < 200009; i++)
    {
        if (prefix[i] >= k)
            result[i] = 1;
    }
    for (int i = 1; i < 200009; i++)
    {
        result[i] += result[i - 1];
    }

    while (q--)
    {
        cin >> l >> r;
        cout << result[r] - result[l - 1] << endl;
    }
}