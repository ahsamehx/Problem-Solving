#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    vector<string> v;
    string name;
    while (n--)
    {
        cin >> name;
        v.emplace_back(name);
    }
    reverse(v.begin(), v.end());
    for (auto &val : v)
    {
        if (s.insert(val).second)
            cout << val << endl;
    }
}