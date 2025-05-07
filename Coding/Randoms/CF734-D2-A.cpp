#include<iostream>
using namespace std;

int main (){

    int num, Ac = 0, Dc = 0;
    cin >> num;
    string str = " ";
    cin >> str;

    for (int i = 0; i < num; i++)
    {
        if ((str[i]) == 'A') Ac++;
        else Dc++;

    }
    if (Ac > Dc) cout << "Anton";
    else if (Ac < Dc) cout << "Danik";
    else cout << "Friendship" << endl;
    

    return 0;
}
