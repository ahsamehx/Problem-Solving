#include <iostream>
using namespace std;

int main()
{
    int n, result = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
            result++;
    }
    cout << result<< endl;
}