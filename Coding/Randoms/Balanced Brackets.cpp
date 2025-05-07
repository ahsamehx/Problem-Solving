#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = n;
    string str;
    while (n--)
    {
        stack<char> sk;
        bool flag = true;
        cin >> str;
        for (auto &val : str)
        {
            if (val == '(' || val == '[' || val == '{')
                sk.push(val);
            else
            {
                if(sk.empty())
                    flag = false;
                else 
                {
                    char ch = sk.top();
                    sk.pop();
                    if (val == ')' && ch == '(') continue;
                    if (val == '}' && ch == '{') continue;
                    if (val == ']' && ch == '[') continue;
                    flag = false;
                }

            }
        }
        flag = flag && sk.empty();
        (flag) ? cout << "YES" : cout << "NO";
    }
}