#include<iostream>
using namespace std;

int main()
{
    int n, result =0;
    cin >> n;
    int arr[n*2];
    for (int i =0; i < n*2; i++)
    {
        cin >> arr[i];
    }
    for(int i =0; i <= n*2-2; i+=2)
    {
        for (int k = 1; k < n*2; k+=2)
        {
            if (arr[i] == arr[k]) result++;
        }
    }
    cout << result << endl;

}