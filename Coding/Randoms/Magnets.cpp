#include<iostream>
using namespace std;

int main ()
{
    int n, counter =0, pole, temp = 0;;
    cin >> n;
    while (n--)
    {
        cin >> pole;
        if (pole != temp)
        {
            counter++;
        }
        temp = pole;

    }
    cout << counter << endl;
    return 0;
}