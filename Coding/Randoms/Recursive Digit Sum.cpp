#include <iostream>
#include <string>
using namespace std;

int summation_of_digits(long long n);
int superDigit(long long sum)
{
    if (sum < 10)
    {
        return sum;
    }
    return superDigit(summation_of_digits(sum));
}

int summation_of_digits(long long n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    string n;
    long long k;
    cin >> n >> k;
    long long sum = 0;
    for (char c : n)
    {
        sum += c - '0';
    }
    cout << superDigit(sum * k) << endl;
    return 0;
}
