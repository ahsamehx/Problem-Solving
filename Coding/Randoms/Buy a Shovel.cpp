#include<iostream>
using namespace std;

int main()
{
    int price, count = 0, faka, total =0;
    cin >> price >> faka;
    while (true)
    {
        count++;
        if((price*count)%10 == 0 || ((price*count)%10)-faka == 0) break;
    }
    cout << count << endl;
}