#include<iostream>
using namespace std;

int main(){

    int num, shoot, x, y;

    cin >> num;
    int data[num+1];

    for (int i = 1; i <= num; i++)
    {
        cin >> data[i];
    }

    cin >> shoot;
    for (int i =0; i< shoot ; i++)
    {
        cin >> x >> y;
        if(x > 1) 
        data[x-1] += data[x] -(data[x] - y) -1;
        if (x < num)
        data[x+1] += data[x] - y;
        data[x]=0;
    }
    for (int i = 1; i <= num; i++)
    {
        cout << data[i] << endl;
    }
}

