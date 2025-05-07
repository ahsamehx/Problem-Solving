#include<iostream>

using namespace std;

int main()
{
    int a =0, b, result = 0, num;
    cin >> num;
    char x[num];

    for (int i =0; i < num; i++)
    {
        cin >> x[i];
    }
    while (num--)
    {
        b = a +1;
        if (x[a] == x[b])
        {
            result++;
        }
        a++;
    }
    cout << result << endl;
}