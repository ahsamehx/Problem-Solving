#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define inf 1e15

int main()
{
    unordered_map<int, int> map;

    int n;
    cin >> n;
    int arr[n];
    for (auto &val : arr)
    {
        cin >> val;
    }

    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
        
    }
    long long max_element = -inf;

    for (auto it = map.begin(); it !=map.end(); it++)
    {
        long long temp = it->second;
        max_element = max(max_element,temp);
    }

    // for (auto it = map.begin(); it !=map.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    
    cout << n - max_element << endl;
}