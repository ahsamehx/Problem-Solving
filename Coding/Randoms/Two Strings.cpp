#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int freq[150] = {0};
        string s1, s2;
        cin >> s1 >> s2;
        bool flag = false;

        for (auto &val : s1)
            freq[val]++;
        for (auto &val : s2)
        {
            if (freq[val] > 0)
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO" << endl;
    }
}