#include<iostream>

using namespace std;

int main(){

    int distinctCount;
    string str = "";
    cin >> str; 

    for (int i = 0; i < str.length(); i++)
    {
        char current = str[i];
        bool isDistinct = true;

        for (int j =0; j < i; j++)
        {
            if (str[j] == current)
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) distinctCount++;
    }

    if (distinctCount%2 == 0) 
    {cout << "IGNORE HIM!" << endl;}
    else {cout << "CHAT WITH HER!" << endl;}

    return 0;
}