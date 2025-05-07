
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i < x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool isWhole(int x)
{
    long double y = sqrt((long double)x);
    if (y != sqrt(x))
        return false;
    return true;
}
// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s1, s2;
        int freq_a[n +1][28] = {0}, freq_b[n +1][28] = {0};

        cin >> s1 >> s2;
        for (int i = 0; i < n; i++)
        {
            for (int  j= 0;j < 28; j++)
            {
                freq_a[i+1][j] = freq_a[i][j];
                freq_b[i+1][j] = freq_b[i][j];

            }
            freq_a[i+1][s1[i]- 'a']++;
            freq_b[i+1][s2[i]- 'a']++;

        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int res = 0;
            
            int freqaa[28]= {0}, freqbb[28] = {0};
            for (int j = 0; j < 28; j++)
            {
                freqaa[j] = freq_a[r+1][j] - freq_a[l][j];
                freqbb[j] = freq_b[r+1][j] - freq_b[l][j];
            }
            for (int i = 0; i < 28; i++)
            {
                if (freqaa[i] != freqbb[i])
                {
                    freqbb[i]--;
                    freqaa[i]--;
                    res += abs((freqbb[i] - freqaa[i]));

                    if (freqbb[i] < 0)
                        freqbb[i] = 0;
                    if (freqaa[i] < 0)
                        freqaa[i] = 0;
                }
            }
            cout << res / 2 << "\n";
        }
    }
}
