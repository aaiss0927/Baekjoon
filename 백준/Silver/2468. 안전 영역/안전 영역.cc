#include <iostream>
#include <vector>
using namespace std;

int N;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(pair<int, int> p, int h, vector<vector<int>>& board, vector<vector<bool>>& visited) {
    visited[p.first][p.second] = true;
    for (int i = 0; i < 4; i++) {
        int x = p.first + dx[i];
        int y = p.second + dy[i];

        if (x < 0 || x >= N || y < 0 || y >= N) {
            continue;
        }

        if (visited[x][y]) {
            continue;
        }

        if (board[x][y] <= h) {
            continue;
        }

        dfs({ x, y }, h, board, visited);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] > max) {
                max = board[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < max; i++) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (!visited[j][k] && (board[j][k] > i)) {
                    dfs({ j, k }, i, board, visited);
                    cnt++;
                }
            }   
        }
        if (cnt > ans) {
            ans = cnt;
        }
    }
    cout << ans;
}