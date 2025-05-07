#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s1;
    string str = "";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            s1.push(str[i]);
        }
        else if (str[i] == '}')
        {
            s1.pop();
        }
    }
    if (s1.empty())

        cout << "Balanced" << endl;

    else
        cout << "Not balanced" << endl;
}
