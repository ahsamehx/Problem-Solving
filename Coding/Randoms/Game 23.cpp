#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
#define line "\n"
const int N = 1e6 + 5;

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/
int ans = 0;
bool solve(int n, int m, int count)
{

    if (n == m)
    {
        ans = count;
        return true;
    }
    if (n > m)
        return false;
    count++;
    if (solve(n * 2, m, count))
        return true;

    if (solve(n * 3, m, count))
        return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (solve(n, m, 0))
        cout << ans << endl;
    else
        cout << -1 << endl;
}