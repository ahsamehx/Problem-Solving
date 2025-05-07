#include <iostream>
#include <iomanip>
#include <cmath>

//cound not solve

using namespace std;

int main()
{
    long long n, introvert, extrovert, universal;
    float tent = 0;
    cin >> n;
    while (n--)
    {
        tent = 0;
        cin >> introvert >> extrovert >> universal;

        tent += introvert;
        if (extrovert % 3 == 0)
        {
            tent += extrovert/3;
            tent += ceil(universal/3.0);
            cout << tent << endl;
        }
        if (extrovert%3 !=0)
        {
            tent += ceil((extrovert+universal)/3.0);
            cout << tent << endl;
        }
        if (extrovert%3 + universal < 3)
            cout << -1 << endl;
        
    }
}