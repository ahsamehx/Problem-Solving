#include <bits/stdc++.h>
using namespace std;
int main()
{

    // Instead of dogging Your footsteps it disappears but you dont notice anything
    // where is your dog
    string str;
    getline(cin, str);
    int freq1[200] = {0};
    int freq2[200] = {0};
    string test;
    getline(cin, test);

    for (auto &val : str)
    {
        freq1[val]++;
    }
    for (int i = 0; i < test.size(); i++)
    {

        if (test[i] == ' ')
            continue;
        freq2[test[i]]++;
    }
    for (auto &val:test)
    {
        if (freq2[val] > freq1[val])
        {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES" << endl;
}