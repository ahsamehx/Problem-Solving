#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e25

int main()
{
    int n, t;
    cin >> t;
    set<int> s;

    while (t--)
    {
        int val;
        bool flag = true;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            auto it = s.insert(val);
            if (!it.second)
            {
                flag = false;
                // break;
            }
        }
        (flag) ? cout << "prekrasnyy" << endl : cout << "ne krasivo" << endl;
        s.clear();
    }
}