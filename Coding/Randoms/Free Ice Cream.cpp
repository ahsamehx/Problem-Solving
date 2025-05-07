#include <iostream>
#include <cstdint>  // Include for int64_t
using namespace std;

int main()
{
    int64_t n, x, distress = 0, amount;  // Change long long to int64_t
    char sign;
    cin >> n >> x;
    while (n--)
    {
        cin >> sign >> amount;
        if(sign == '+')
        {
            x += amount;
        }
        else 
        {
            if (x >= amount)
                x -= amount;
            else
                distress++;
        }
    }
    cout << x << " " << distress << endl;
}
