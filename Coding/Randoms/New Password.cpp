#include <iostream>
using namespace std;

int main()
{
    int n, k;
    char letter;
    string all = "abcdefghijklmnopqrstuvwxyz";
    string use = "";
    string final = "";
    string password = "";
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        use += all[i];
    for (int i = 0; i < n; i++)
    {
        final += use;
    }
    for (int i = 0; i < n; i++)
    {
        password += final[i];
    }
    cout << password << endl;
}