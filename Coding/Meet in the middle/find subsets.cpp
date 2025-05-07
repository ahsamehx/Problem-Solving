#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 5;
#define Ahmed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mul(long long x, long long y, const long long& mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long& mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/
int n, s, res =0;
int arr[N];
map <int, int> mp;

void solve(int idx, int sum)
{
    if (idx== n/2)
    {
        mp[sum]++;       
        return;
    }
    solve(idx+1, sum + arr[idx]);
    solve(idx+1, sum);

}

void solve2(int idx, int sum)
{
    if (idx == n)
    {
        if(mp.count(sum))
            res+= mp[s - sum];
        return;
    }
    solve2(idx+1, sum + arr[idx]);
    solve2(idx+1, sum);
}

signed main()
{
    Ahmed
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve(0, 0);
    solve2(n/2, 0);
    cout << res << endl;
}