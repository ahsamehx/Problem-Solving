#include <iostream>
#include <set>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[26] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        arr[str[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
            res++;
    }
    (res % 2 == 0) ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
}

//================================ Another Solution ==========================
// int main()
// {
//     string str;
//     cin >> str;
//     set<char> st;

//     for (int i = 0; i < str.size(); i++)
//     {
//         st.insert(str[i]);
//     }
//     (st.size() % 2 == 0) ? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
// }
