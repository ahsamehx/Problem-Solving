#include<iostream>
#include <cctype>
#include <ctype.h>
using namespace std;

string ToLowerCase (string x)
{
    string result = "";
     for (char c : x) {
        result += tolower(c);
    }
    return result;
}
int main () {

    string str0, str1, str3, str4;
    cin >> str3 >> str4;

    str0 = ToLowerCase(str3);
    str1 = ToLowerCase(str4);

    for (int i = 0; i < str0.length(); i++)
    {
        if (str0[i] < str1[i]) 
        {
            cout << -1 << endl;
            break;
        }
        else if (str0[i] > str1[i])
        {
            cout << 1 << endl;
            break;
        }
        else if (i == str0.length() -1) cout << 0 << endl;
    }


    return 0;
}