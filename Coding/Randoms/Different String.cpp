#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s; // codeforces
        char ch;
        bool flag = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i + 1] != s[i])
            {
                ch = s[i + 1];
                flag = true;
                break;
            }
        }
        (flag) ? cout << "YES" : cout << "NO";
        cout << endl;
        deque<char> r;
        bool first = true;
        if (flag)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ch && first)
                {
                    first = false;
                    continue;
                }
                r.emplace_back(s[i]);
            }
            if ((s[s.size() - 1] == ch))
                r.push_front(ch);
            else
                r.emplace_back(ch);
        }
        for (auto &val : r)
        {
            cout << val;
        }
        if (flag)
            cout << endl;
    }
}