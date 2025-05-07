#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, op;
    cin >> t;
    string str = "";
    stack<string> past_str;
    while (t--)
    {
        string temp = "";
        int index;
        cin >> op;
        
        if (op == 1)
        {
            past_str.push(str);
            cin >> temp;
            str.append(temp);
        }
        else if (op == 2)
        {
            past_str.push(str);
            cin >> index;
            while(index--) str.pop_back();
        }
        else if (op == 3)
        {
            cin >> index;
            index--;
            cout << str[index] << endl;
        }
        else if (op == 4)
        {
            str = past_str.top();
            past_str.pop();
        }
    }
}