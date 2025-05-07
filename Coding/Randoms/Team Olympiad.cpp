#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int size, num, result;
    cin >> size;
    vector<int> arr1, arr2, arr3;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        if (num == 1)

            arr1.push_back(i + 1);

        else if (num == 2)

            arr2.push_back(i + 1);

        else

            arr3.push_back(i + 1);
    }

    int ans = min(min(arr1.size(),arr2.size()), arr3.size());
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << arr1[i] << " " << arr2[i] << " " << arr3[i] << endl;
    }
}
