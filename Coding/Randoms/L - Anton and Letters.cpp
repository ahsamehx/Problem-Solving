#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int arr[26] = {0};
    if (str.size() < 3)
    {
        cout << 0 << endl;
        exit(0);
    }

    for (int i = 1; i < str.size(); i += 3)
    {
        arr[str[i] - 'a']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
            res++;
    }

    cout << res << endl;
}