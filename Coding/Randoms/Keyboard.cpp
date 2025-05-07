#include <bits/stdc++.h>
using namespace std;

int main()
{
    char shift;
    string str = "qwertyuiopasdfghjkl;zxcvbnm,./";
    cin >> shift;
    string input;
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        size_t pos = str.find(input[i]);

        if (shift == 'R')
        {
            cout << str[pos - 1];
        }
        else
        { // Shift is 'L'
            cout << str[pos + 1];
        }
    }
    cout << endl;
    return 0;
}
////////////////////////////////////////////////////////////////////////
// int main()
// {
//     char shift;
//     string str = "qwertyuiopasdfghjkl;zxcvbnm,./";
//     set<char> database(str.begin(), str.end());
//     cin >> shift;
//     string input;
//     cin >> input;
//     if (shift == 'R')
//     {
//         for (int i = 0; i < input.size(); i++)
//         {
//             auto it = database.find(input[i]);
//             it--;
//             cout << *it;
//         }
//     }
//     else                                            // s;;upimrrfod;pbr
//     {
//         for (int i = 0; i < input.size(); i++)
//         {
//             auto it = database.find(input[i]);
//             it++;
//             cout << *it;
//         }
//     }
// }