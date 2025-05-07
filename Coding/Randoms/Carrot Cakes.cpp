#include <iostream>
#include <cmath>

using namespace std;

void carrotCakes()
{
    double n{0}, t{0}, k{0}, d{0}, time_1{0}, time_2{0};
    int n_left;
    cin >> n >> t >> k >> d;

    if (k >= n)
    {
        cout << "NO";
        return;
    }

    if (d >= t)
    {
        time_1 = ceil(ceil(n / k) * t);
        n = n - floor(d / t) * k;
        time_2 = d + ceil((n * 1.0) / (k * 2)) * t;
    }
    else
    {

        time_1 = ceil(ceil(n / k) * t);

        time_2 = d + ceil((n * 1.0) / (k * 2)) * t;
    }

    (time_2 < time_1) ? cout << "YES" : cout << "NO";
}

int main()
{
    carrotCakes();
    return 0;
}
