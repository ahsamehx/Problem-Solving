#include <iostream>
using namespace std;

int result = 0;
int hello(int arr[], int n)
{
    if (n == -1)
        return result;
    result += arr[n-1];
    return hello(arr, n - 1);
}

int main()
{
    int num, n;
    cin >> num;
    int res[num];
    for (int i = 0; i < num; i++)
    {
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        int result = hello(arr, n - 1);
        res[i] = result;
    }

    for (int i = 0; i < num; i++)
    {
        cout << " Case " << i+1 << ": " << res[i] << endl;
    }
}