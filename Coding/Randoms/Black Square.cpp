#include<iostream>
using namespace std;

int main()
{
    int x, count =0, arr[4];
    string s;

    for(int i =0; i < 4; i++)
    {
        cin >> arr[i];
    }

    cin >> s;

    for (int i =0; i < s.length(); i++)
    {
        x = s[i] - '0';
        count += arr[x-1];
    }

cout << count << endl;

}