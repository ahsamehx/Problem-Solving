#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e10
const int N = 2e6 + 20;
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
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = inf;
        for(int one = 0; one <= 2; one++){
            for(int three = 0; three <= 1; three++){
                for(int six = 0; six <= 4; six++){
                    for(int ten = 0; ten <= 2; ten++){
                        int total_sum = 1*one + 3*three + 6*six + 10*ten;
                        if(total_sum <= n && (n-total_sum)%15 == 0){
                            sum = min(sum, one + three + six + ten + (n-total_sum)/15);
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
}