#include <iostream>
using namespace std;

int Fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
    int n, result;
    cin >> n;

    result = Fibo(n);
    cout << result << endl;
}