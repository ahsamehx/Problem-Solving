#include<iostream>

using namespace std;

//wrong answer when handling large numbers 
int main ()
{
    long long num;
    __int128 sum =1;
    for(int i =0; i< 4; i++)
    {
        cin >> num;
        sum *=num;
    }
    num = sum;
    string str = to_string(num);
    cout << str[-2] << endl;

}