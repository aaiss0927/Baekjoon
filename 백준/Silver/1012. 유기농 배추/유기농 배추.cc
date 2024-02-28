#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int grid[50][50];
bool visited[50][50];
int cnt;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

bool can_go(int x, int y) {
	return (in_range(x, y) && !visited[x][y] && grid[x][y] == 1);
}

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (can_go(nx, ny)) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T; cin >> T;

	while (T--) {
		cin >> m >> n >> k;

		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				grid[i][j] = 0;
				visited[i][j] = false;
			}
		}

		while (k--) {
			int x, y; cin >> x >> y;
			grid[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					q.push({ i, j });
					BFS();
					cnt++;
				}
			}
		}		

		cout << cnt << '\n';
	}
}