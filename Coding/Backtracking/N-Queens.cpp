#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
#define line "\n"
const int N = 1e6 + 5;
#define Ahmed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long mul(long long x,long long y,const long long&mod){return ((x%mod)*(y%mod))%mod;}
long long add(long long x,long long y,const long long&mod){return (((x%mod)+(y%mod))%mod+mod)%mod;}

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/
int n;
int res = 0;
bool column[20];
bool diag1[20];
bool diag2[20];
void solve (int row)
{
    if (row == n)
    {
        res++;
        return;
    }

    for (int col =0; col < n; col++)
    {
        if(column[col] || diag1[row + col] || diag2 [row - col + n -1]) continue;
        
        column[col] = true,  diag1[row + col] = true, diag2 [row - col + n -1] = true;
        solve(row+1);
        column[col] = false,  diag1[row + col] = false, diag2 [row - col + n -1] = false;
    }
}
signed main()
{
    Ahmed
    cin >> n;
    solve(0);
    cout << res << line;
}