#include<iostream>
using namespace std;

int main()
{
    string str;
    int let1, let2, result =0;
    cin >> str;
    let1 = 'a' -'0';
    let2 = str[0] - '0';
    
    for (int i =0; i < str.length(); i++)
    {
        if (abs(let2 - let1) >= 13) result +=  abs(abs(let2 -let1) - 26);
        else result+= abs(let2 -let1);
        let1 = str[i] - '0';
        let2 = str[i+1] - '0';
    }
    cout << result << endl;
}