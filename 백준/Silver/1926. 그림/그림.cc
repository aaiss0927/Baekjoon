#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int cnt = 0;
int area;
int maxi = -1;

bool in_range(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}

bool can_go(int x, int y) {
	return in_range(x, y) && !visited[x][y] && board[x][y];
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> point = q.front(); q.pop();
		int x, y;
		tie(x, y) = point;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (can_go(nx, ny)) {
				area++;
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	if (area > maxi)
		maxi = area;
}

int main() {
	cin >> n >> m;
	board = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!can_go(i, j))
				continue;

			area = 1;
			q.push({ i, j });
			visited[i][j] = true;
			bfs();
			cnt++;
		}
	}

	if (cnt == 0)
		cout << "0\n0";

	else
		cout << cnt << '\n' << maxi;
}