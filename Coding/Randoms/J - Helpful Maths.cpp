#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> v;
    for (int i = 0; i < str.size(); i += 2)
    {
        v.push_back(str[i] - '0');
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
            cout << v[i] << '+';
        else
            cout << v[i];
    }
}