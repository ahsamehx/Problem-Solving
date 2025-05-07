#include <bits/stdc++.h>

using namespace std;
int main()
{
    int x, y;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        cout << min(x, y) << " " << max(x, y) << endl;
    }
}
