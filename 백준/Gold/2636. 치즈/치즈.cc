#include <iostream>
#include <queue>
using namespace std;

int n, m;
int grid[100][100];
int next_grid[100][100];
bool visited[100][100];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

bool can_go(int x, int y) {
	return (in_range(x, y) && !visited[x][y] && grid[x][y] == 0);
}

void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			next_grid[i][j] = grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

void setdown() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] = next_grid[i][j];
		}
	}
}

bool is_clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (next_grid[i][j] == 1) {
				return false;
			}
		}
	}

	return true;
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

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int t = 0;

	while (true) {
		setup();
		visited[0][0] = true;
		q.push({ 0, 0 });
		BFS();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (in_range(nx, ny) && visited[nx][ny]) {
							next_grid[i][j] = 0;
							break;
						}
					}
				}
			}
		}

		t++;

		if (is_clear()) {
			break;
		}

		setdown();
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << t << '\n' << cnt;
}