#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d, element;
        cin >> n >> d;
        vector<int> v(n); // Create a vector of size n

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        if (v[0] + v[1] <= d || v.back() <= d) // Check if the sum of the two smallest elements is less than or equal to d
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;

        
    }
    return 0;
}
