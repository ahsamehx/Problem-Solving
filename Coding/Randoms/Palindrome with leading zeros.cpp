#include <iostream>

using namespace std;

bool plaindrome(string str, int size)
{
    int q = size;
    for (int i = 0; i < size/ 2 + 1; i++,q--)
    {
        if (i == q || q < i)
        {
            break;
        }

        if (str[i] != str[q])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string str = to_string(n);

    //====== handling the zeros ===========
    int q = str.size() - 1;
    for (; str[q] == '0'; q--)
    {
    }
    (plaindrome(str, q)) ? cout << "Yes" : cout << "No";
}
