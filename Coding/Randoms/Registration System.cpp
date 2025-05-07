#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, int> database;
    while (n--)
    {
        string str;
        cin >> str;
        if (database.count(str) > 0)
        {
            auto it = database.find(str);
            cout << str << it->second << endl;
            it->second++;
        }
        else
        {
            cout << "OK" << endl;
            database.insert(make_pair(str, 1));
        }
    }
}