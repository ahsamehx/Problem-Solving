#include<bits/stdc++.h>

using namespace std;

#define int long long
#define inf 1e18
const int N = 8;

int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool valid (int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

int minKnightCost(int sx, int sy, int ex, int ey) {
    vector<vector<int>>cost(N, vector<int>(N, inf));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    cost[sx][sy] = 0;
    pq.push({0, {sx, sy}});
    while (!pq.empty()) {
        auto[curCost, pos] = pq.top();
        int x = pos.first, y = pos.second;
        pq.pop();
        if (x == ex && y == ey) {return curCost;}
        for (int i = 0; i < 8; i++) {
            int nx = x + moves[i][0], ny = y + moves[i][1];
            if (valid(nx, ny)) {
                int moveCost = (x*nx + y*ny);
                if (cost[nx][ny] > moveCost + curCost) {
                    cost[nx][ny] = moveCost + curCost;
                    pq.push({cost[nx][ny], {nx, ny}});
                }
            }
        }
    }
    return -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sx, sy, ex, ey;
    while (cin >> sx >> sy >> ex >> ey) {
        minKnightCost(sx, sy, ex, ey);
        cout << minKnightCost(sx, sy, ex, ey) << endl;
    }
    return 0;
}