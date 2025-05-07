#include <iostream>
#include <queue>

using namespace std;

int main()
{
#define int long long
    int n, potion, sum = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> potion;
        pq.push(potion);
        sum += potion;
        if (sum < 0)
        {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
}