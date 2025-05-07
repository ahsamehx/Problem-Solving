#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 1e6 + 20;
#define Ahmed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
long long mul(long long x, long long y, const long long &mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long &mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

signed main()
{
    bool sieve[N];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 0; i < N; i++)
    {
        if (sieve[i])
            primes.emplace_back(i);
    }

    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int res = inf;
    // iterate over each column and row, find the lower bound of each number and cal the difference between the number and its lower bound
    // Row iteration

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            temp += (*lower_bound(primes.begin(), primes.end(), arr[i][j]) - arr[i][j]);
        }
        res = min(res, temp);
    }

    // Column iteration

    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += (*lower_bound(primes.begin(), primes.end(), arr[j][i]) - arr[j][i]);
        }
        res = min(res, temp);
    }

    cout << res << endl;
}
