#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e25

int main()
{
    string s;
    cin >> s;
    int size = s.size();
    int prefix[size] = {0}, suffix[size] = {0};

    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'L')
            prefix[i] = 1;
        if (i)
            prefix[i] += prefix[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
            suffix[i] = 1;
        if (i + 1 < size)
            suffix[i] += suffix[i + 1];
    }
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == 'O')
            result += prefix[i] * suffix[i];
    }
    cout << result << endl;
}