#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;

// اللَّهُمَّ انفَعْني بما عَلَّمتَني، وعلِّمْني ما يَنفعُني، وارزُقْني عِلمًا تَنفعُني به

/*======================================ahsamehx===========================================*/
vector<int> v;
int l, r, x = 0;
void lucky_nums(string current)
{
    if (current.length() > 10)
        return;

    if (!current.empty())
    {
        int num = stoll(current);
        v.push_back(num);
    }
    lucky_nums(current + '4');
    lucky_nums(current + '7');
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> r;
    int res = 0;
    int lucky = 4;
    lucky_nums("");
    sort(v.begin(), v.end());
    for (int i = l; i <= r; i++)
    {
        if (lucky < i)
        {
            auto temp = lower_bound(v.begin(), v.end(), i);
            lucky = *temp;
        }
        res += lucky;
    }
    cout << res << endl;
}