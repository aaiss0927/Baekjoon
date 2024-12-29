#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int group_id = 2;
queue<pair<int, int>> q;

bool in_range(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

bool can_go(int x, int y) {
    return in_range(x, y) && !visited[x][y] && !grid[x][y];
}

int bfs(int x, int y) {
    int size = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        grid[x][y] = group_id;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (can_go(nx, ny)) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                size++;
            }
        }
    }

    return size;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string row; cin >> row;
        
        for (int j = 0; j < m; j++)
            grid[i][j] = row[j] - '0';
    }

    vector<vector<int>> result = grid;
    vector<int> group_size;
    group_size.push_back(0);
    group_size.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (can_go(i, j)) {
                visited[i][j] = true;
                q.push({ i, j });
                group_size.push_back(bfs(i, j));
                group_id++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                set<int> adj_group;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (in_range(ni, nj))
                        adj_group.insert(grid[ni][nj]);
                }

                for (int g : adj_group)
                    result[i][j] += group_size[g];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << result[i][j] % 10;
        cout << '\n';
    }
}