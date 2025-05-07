
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        deque<int> v;
        int res = 0;
        for (auto &val : str)
            v.emplace_back(val);

        for (int i = 0; i < v.size(); i++) // 11010
        {
            if (v.at(i) == 0 && i == v.size() - 1)
            {
        
                v.at(i) = 1;
                res += 1;
            }
            else if (v.at(i) == 0)
            {
    
                v.at(i) = 1;
                res += 2;
            }
        }
        if (res)
            cout << res << endl;
        else
            cout << 1 << endl;
    }
}
