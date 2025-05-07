#include<iostream>
#include<cctype>

using namespace std; 

int main ()
{

    string str;
    cin >> str;
    int upper = 0, lower = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i])) upper++;
        else lower++;
    }
    if (upper > lower)
    {
        for(int i = 0; i < str.length(); i++)
        {
            cout << toupper(str[i]);
        }
    } 
    else 
    {
        for(int i = 0; i < str.length(); i++)
        {
            cout << tolower(str[i]);
        }
    }

    return 0;
}