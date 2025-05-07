#include<iostream>
using namespace std;

int main()
{
    string s, t;
    int key =0;
    cin >> s >> t;
    for (int i =0; i < t.length(); i++)
    {
        if (s[key] == t[i])
        key++;
    }
    cout << key +1 << endl;
}