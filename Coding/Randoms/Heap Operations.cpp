#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    multiset<int> ms;
    vector<pair<string, int>> v;
    while (n--)
    {
        int num;
        string str;
        cin >> str;
        if (str[0] == 'i')
        {
            count++;
            cin >> num;
            ms.insert(num);
            // cout << "insert " << num << endl;
            v.push_back(make_pair("insert ", num));
        }
        else if (str[0] == 'g')
        {

            bool flag = false;
            cin >> num;
            if (!(ms.count(num)))
            {
                count++;
                flag = true;
                ms.insert(num);
            }
            while (*ms.begin() != num)
            {
                ms.erase(ms.begin());
                v.push_back(make_pair("removeMin ", 0));
                count++;
            }
            if (flag)
                v.push_back(make_pair("insert ", num));
            cout << "getMin " << num << endl;
            count++;
        }
        else if (str[0] == 'r')
        {
            int temp = *ms.begin();
            while (*ms.begin() == temp)
            {
                count++;
                ms.erase(ms.begin());
                v.push_back(make_pair("removeMin ", 0));
            }
        }
    }
    cout << count << endl;
    for (auto &val : v)
    {
        if (val.second == 0)
            cout << val.first << endl;
        else
            cout << val.first << val.second << endl;
    }
}