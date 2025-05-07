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
int n;
int arr[N];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool isPrime(int x)
{
    for (auto n : prime)
    {
        if (x == n)
            return true;
    }
    return false;
}

bool prime_array(int arr[])
{
    for (int i = 0; i < n -1; i++)
    {
        if (!(isPrime (arr[i] + arr[i+1])))
            return false;
    }
    return true;
}

void solve (int idx, bool visit[])
{
    
    if(idx == n)
    {
        if(!isPrime(arr[n-1] + 1))
            return;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (visit[i]) continue;
        if(isPrime(arr[i]+arr[idx -1]))
        {
            visit[i] =1;
            solve(idx+1, visit);
            visit[i] = 0;
        }
    }
    
    
}

signed main ()
{
    bool visit[20];
    cin >> n;
    for (int i = 0; i<n; i++)
        arr[i] = i+1;
    solve(1, visit);
}