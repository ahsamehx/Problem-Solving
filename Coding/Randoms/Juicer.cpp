#include<iostream>
using namespace std;

int main ()
{
    int n, b, d, waste =0, result = 0;
    cin >> n >> b >> d;
    int arr[n];

    for (int i = 0; i< n; i++)
    {
        cin >> arr[i];
        if (arr[i]<= b) 
            waste += arr[i];
        if (waste > d){
            result++;
            waste =0;
        }
            
    }
    cout << result << endl;
}


