#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> sk;
    for (auto &val : str)
    {
        if (sk.empty())
        {
            sk.push(val);
        }
        else
        {
            if (sk.top() != val)
            {
                sk.push(val);
            }
            else
            {
                sk.pop();
            }
        }
    }
    (sk.empty()) ? cout << "Yes" : cout << "No";
}