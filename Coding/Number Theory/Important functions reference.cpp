#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e5 + 20;
#define Ahmed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
long long mul(long long x, long long y, const long long &mod) { return ((x % mod) * (y % mod)) % mod; }
long long add(long long x, long long y, const long long &mod) { return (((x % mod) + (y % mod)) % mod + mod) % mod; }

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

// (a * b) % m = ((a % m) * (b % m)) % m
// (a + b) % m = ((a % m) + (b % m)) % m
// (a - b) % m = ((a % m) - (b % m) + m) % m   ----------------------- (a % m) - (b % m) might be negative so we add m to it.

// a%b = a - [a/b] * b  --> equation 

/*
    Find the Mod inverse:
    1- if the mod is prime 
        fast_power(b, mod -2, mod) which is equal to (b ^ mod-2) % mod
    2- l
*/
int power(int b, int p)
{
    if (p == 0)
        return 1;

    int result = 1;

    while (p > 0)
    {
        if (p % 2 == 0)
        {
            b *= b;
            p /= 2;
        }
        else
        {
            result *= b;
            p--;
        }
    }
    return result;
}

signed main()
{
    cout << LCM(2,6) << endl;
}