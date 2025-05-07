#include <bits/stdc++.h>
#define int long long
using namespace std;

int bfs(int n, int m) {
    queue<pair<int, int>> q;
    vector<bool> visited(2 * max(n,m) + 4, false);

    q.push({n, 0});    //6666 666

    visited[n] = true;

    while (!q.empty()) {
        int num = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (num == m) return steps;

        if (num < m && !visited[num * 2]) {
            q.push({num * 2, steps + 1});
            visited[num * 2] = true;
        }

        if (num > 1 && !visited[num - 1]) {
            q.push({num - 1, steps + 1});
            visited[num - 1] = true;
        }
    }

    return -1;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << endl;
    return 0;
}
