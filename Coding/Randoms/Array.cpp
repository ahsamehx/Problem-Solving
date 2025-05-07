#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> v;
    int neg, pos;
    bool flagpos = true, flagneg = true;
    for (auto &val : arr)
    {
        cin >> val;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0 && flagneg)
        {
            neg = arr[i];
            flagneg = false;
            continue;
        }
        if (arr[i] > 0 && flagpos)
        {
            pos = arr[i];
            flagpos = false;
            continue;
        }
        v.push_back(arr[i]);
    }

    cout << "1 " << neg << endl;
    if (pos == 0)
    {
        cout << "2 ";
        // int count = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < 0)
            {
                cout << v[i] << " ";
                v.erase(v.begin() + i);
                i--;
                if (v.size() == n - 3)
                    break;
            }
        }
        cout << endl;
    }
    else
        cout << "1 " << pos << endl;

    cout << v.size() << " ";
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}