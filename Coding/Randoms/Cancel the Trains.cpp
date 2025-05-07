#include <bits/stdc++.h>
using namespace std;

int main()
{
    int input, n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int result = 0;
        int freq[104] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            freq[input]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> input;
            if (freq[input] == 1)
                result++;
        }
        cout << result << endl;
    }
}

// int main()
// {
//     int input, n, m, t;

//     cin >> t;
//     while (t--)
//     {
//         multiset<int> database;
//         cin >> n >> m;
//         int result = 0;
//         for (int i = 0; i < n + m; i++)
//         {
//             cin >> input;
//             if (database.count(input) == 0)
//                 database.insert(input);
//             else
//                 result++;
//         }
//         cout << result << endl;
//     }
// }
