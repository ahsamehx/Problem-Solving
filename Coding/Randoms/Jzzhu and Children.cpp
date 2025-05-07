#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    queue<pair<int, int>> q;
    for (auto &val : v)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++)
    {
        q.push({v[i], i});
    }
    while (q.size() != 1)
    {
        if ((q.front().first) > m)
        {
            q.front().first -= m;
            q.push(q.front());
            q.pop();
        }
        else
        {
            q.pop();
        }
    }
    cout << q.front().second + 1 << endl;
}
