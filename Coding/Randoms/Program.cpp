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
        int n, m;
        cin >> n >> m;
        int prefix_sum[n], prefix_mx[n], prefix_mn[n], suffix_mn[n], suffix_mx[n];
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
                prefix_sum[i] = -1;
            else
                prefix_sum[i] = 1;
            (i) ? prefix_sum[i] = prefix_sum[i - 1] + prefix_sum[i] : prefix_sum[i];
        }
        prefix_mx[0] = prefix_sum[0];
        for (int i = 1; i < n; i++)
        {
            prefix_mx[i] = max(prefix_sum[i], prefix_mx[i - 1]);
        }

        prefix_mn[0] = prefix_sum[0];
        for (int i = 1; i < n; i++)
        {
            prefix_mn[i] = min(prefix_sum[i], prefix_mn[i - 1]);
        }

        suffix_mx[n - 1] = prefix_sum[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix_mx[i] = max(prefix_sum[i], suffix_mx[i + 1]);
        }
        suffix_mn[n - 1] = prefix_sum[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix_mn[i] = min(prefix_sum[i], suffix_mn[i + 1]);
        }

        for (int i = 0; i < m; i++)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int pre_mx = (l - 1 < 0 ? 0 : max((int)0, prefix_mx[l - 1]));
            int pre_mn = (l - 1 < 0 ? 0 : min((int)0, prefix_mn[l - 1]));
            int suf_mx = (r + 1 == n ? 0 : max((int)0, suffix_mx[r + 1] - (prefix_sum[r] - (l)? prefix_sum[l] :0)));
            int suf_mn = (r + 1 == n ? 0 : min((int)0,suffix_mn[r + 1] - (prefix_sum[r] -  (l)? prefix_sum[l] :0)));
            cout << max(pre_mx, suf_mx) - min(pre_mn, suf_mn) + 1 << endl;
        }
    }
}