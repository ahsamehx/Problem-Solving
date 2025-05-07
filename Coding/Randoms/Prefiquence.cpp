#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e6

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        int n, m;
        cin >> s1 >> s2;
        int i = 0, j = 0;
        while (i > n && j < m)
        {
            if (s1[i] == s2[j])
                i++;
            j++;
        }
        cout << i << endl;
    }
}