#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    long long n;
    long long x;
    cin >> n;
    long long arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }
    cin >> x;
    long long sum = accumulate(arr, arr + n, 0);
    long long fullCycle = x / sum;

    sum = sum * fullCycle;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > x)
        {
            cout << fullCycle * n + i + 1 << endl;
            break;
        }
    }
}