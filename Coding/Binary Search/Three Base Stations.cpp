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

int arr[N];
int n;
double l = 0, r = 1e9;
vector<int> ans;

bool solve(double x) {
    double idx = arr[0] + x;
    int count = 1;
    ans.clear();

    for (int i = 1; i < n; i++) {
        if (count > 3)
                return false;
        if (arr[i] > idx + x) {
            count++;
            idx = arr[i] + x;
        }
    }
    return (count <= 3);
}

signed main() {
    Ahmed
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    
    while (r - l > 1e-7) {
        double mid = l + (r - l) / 2.0;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }

    cout << fixed << setprecision(6) << r << endl;
    int pos = 0;
    cout << arr[0] + r << " ";
    for (int i =0; i < n; i++)
    {
        if(pos + r >= arr[i])
            continue;
        cout << arr[i] + r << " ";
    }
    cout << endl;

    return 0;
}
