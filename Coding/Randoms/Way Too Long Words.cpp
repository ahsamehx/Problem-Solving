#include <iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    string input;
    cin >> n;
    string result[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input.length() <= 10)

            result[i] = input;

        else
        {
            result[i] = input[0]+to_string(input.length()-2)+input[input.length()-1];
        }
    }
    for (auto str:result)
    {
        cout << str << endl;
    }
}