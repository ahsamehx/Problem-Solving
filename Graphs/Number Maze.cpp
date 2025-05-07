#include<bits/stdc++.h>

using namespace std;

#define int long long
#define inf 1e18
const int N = 8;
int n, m;
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid (int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int DJK (int n,int m, vector<vector<int>> &board) {

    vector<vector<int>> cost(n, vector<int>(m, inf));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    cost[0][0] = board[0][0];
    pq.emplace(make_pair(cost[0][0], make_pair(0, 0)));
    while (!pq.empty()) {
        auto [curcost, curpos] = pq.top();
        int x = curpos.first, y = curpos.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + moves [i][0], ny = y + moves [i][1];
            if (valid(nx, ny)) {
                if (cost[nx][ny] > curcost + board[nx][ny]) {
                    cost[nx][ny] = curcost + board[nx][ny];
                    pq.emplace(make_pair(curcost + board[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
    return cost[n-1][m-1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> board(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                board[i][j] = x;
            }
        }

        int ans = DJK(n,m,board);

        cout << ans << '\n';

    }
}