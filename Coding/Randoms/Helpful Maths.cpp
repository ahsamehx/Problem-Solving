#include <iostream>
using namespace std;

int main()
{
    string str, result{};
    int count1 = 0, count2 = 0, count3 = 0;
    cin >> str;

    for (int i = 0; i < str.length(); i = i + 2)
    {
        if (str[i] == '1')
            count1++;
        else if (str[i] == '2')
            count2++;
        else
            count3++;
    }
    for (int i = 0; i < str.length() / 2 + 1; i++)
    {
        if (count1 > 0)
        {
            result += '1';
            count1--;
        }

        else if (count2 > 0)
        {
            result += '2';
            count2--;
        }
        else if (count3 > 0)
        {
            result += '3';
            count3--;
        }
        if (i == str.length() / 2)
            break;

        result += '+';
    }
    cout << result << endl;
}