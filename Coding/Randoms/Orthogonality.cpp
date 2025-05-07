#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr0[n], arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr0[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr0[i] * arr1[i];
    }
    (sum == 0) ? cout << "Yes" : cout << "No";
}