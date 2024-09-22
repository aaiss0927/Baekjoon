#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int grid[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> q;

bool in_range(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}

bool can_go(int x, int y) {
	return in_range(x, y) && !visited[x][y] && grid[x][y];
}

void bfs() {
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (can_go(nx, ny)) {
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int sx, sy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 2) {
				sx = i; sy = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0)
				dist[i][j] = 0;
			else
				dist[i][j] = -1;
		}
	}

	visited[sx][sy] = true;
	dist[sx][sy] = 0;
	q.push({ sx, sy });
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}