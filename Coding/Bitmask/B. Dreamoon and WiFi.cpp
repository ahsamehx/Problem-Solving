#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int sum1 = 0, sum2 = 0, sumq = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if(s1[i] == '+')
            sum1++; 
        else if (s1[i] == '-')
            sum1--;
        
        if(s2[i] == '+')
            sum2++;
        else if (s2[i] == '-')
            sum2--;

        if (s2[i] == '?')
            sumq++;
    }

    int res = 0;
    for (int i = 0; i < (1 << sumq); i++)
    {
        int temp = sum2;
        for (int j = 0; j < sumq; j++)
        {
            if (i & (1 << j))
                temp++;
            else 
                temp--;
        }
        if (temp == sum1)
            res++;
    }

    cout << fixed << setprecision(12) << double(res)/(1 << sumq) << endl;

}