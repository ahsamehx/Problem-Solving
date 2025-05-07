#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool flag = false;
        if (d > c)
            swap(c, d);
        if ((b < c && b > d) && !(a < c && a > d))
            flag = true;
        else if ((a < c && a > d) && !(b < c && b > d))
            flag = true;

        (flag) ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}