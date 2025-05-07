#include<iostream>
using namespace std;

int main ()
{
    int n, b, d, waste =0, result = 0;
    cin >> n >> b >> d;


    for (int i = 0; i< n; i++)
    {
        int x;
        cin >> x;
        if (x<= b) 
            waste += x;
        if (waste > d){
            result++;
            waste =0;
        }
            
    }
    cout << result << endl;
}


