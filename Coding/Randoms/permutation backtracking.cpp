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
/*======================================ahsamehx===========================================*/
int n;
bool vis[N];
vector<int> per;

void solve(int cur = 0)
{
    if (per.size() == n)
    {
        for(auto&val:per)
            cout << val << " ";
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            per.emplace_back(i);
            solve(i+1);
            per.pop_back();
        }
    }
}

signed main()
{
    cin >> n;
    solve(n);
}