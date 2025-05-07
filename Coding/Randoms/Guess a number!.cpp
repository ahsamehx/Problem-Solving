#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e9
const int N = 1e6 + 5;
/*======================================ahsamehx===========================================*/

signed main()
{
    int n;
    int left = -2e9, right = 2e9, res = 0;
    cin >> n;
    while (n--)
    {
        string op;
        char check;
        int x;
        cin >> op >> x >> check;
        if (op == ">")
        {
            if (check == 'Y')
                left = max(left, x + 1);
            else
                right = min(right, x);
        }
        else if (op == "<")
        {
            if (check == 'Y')
                right = min(right, x - 1);
            else
                left = max(left, x);
        }
        else if (op == "<=")
        {
            if (check == 'Y')
                right = min(right, x);
            else
                left = max(left, x + 1);
        }
        else if (op == ">=")
        {
            if (check == 'Y')
                left = max(left, x);
            else
                right = min(right, x - 1);
        }
    }
    if (left > right)
        cout << "Impossible" << endl;
    else
        cout << (right + left) / 2 << endl;
}