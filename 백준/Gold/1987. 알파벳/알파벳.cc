#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int R, C;
vector<vector<char>> board;
vector<vector<bool>> visited;
bool is_used[26];
int maxi = -1;
int cnt = 1;

bool in_range(int x, int y) {
    return (x >= 0 and x < R) and (y >= 0 and y < C);
}

bool can_go(int x, int y) {
    return (in_range(x, y) && !visited[x][y] && !is_used[board[x][y] - 'A']);
}

bool is_finished(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (can_go(n_x, n_y)) {
            return false;
        }
    }
    return true;
}

void back_tracking(int x, int y) {
    if (cnt == 26) {
        cout << 26;
        exit(0);
    }

    if (is_finished(x, y)) {
        if (cnt > maxi) {
            maxi = cnt;
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (!can_go(n_x, n_y)) {
            continue;
        }

        cnt++;
        visited[n_x][n_y] = true;
        is_used[board[n_x][n_y] - 'A'] = true;
        back_tracking(n_x, n_y);
        is_used[board[n_x][n_y] - 'A'] = false;
        visited[n_x][n_y] = false;
        cnt--;
    }
}

int main() {
    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<bool>>(R, vector<bool>(C));

    for (int i = 0; i < R; i++) {
        string temp; cin >> temp;

        for (int j = 0; j < C; j++) {
            board[i][j] = temp[j];
        }
    }

    visited[0][0] = true;
    is_used[board[0][0] - 'A'] = true;
    back_tracking(0, 0);
    cout << maxi;
}