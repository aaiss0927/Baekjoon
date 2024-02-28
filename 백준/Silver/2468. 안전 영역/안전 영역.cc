#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int grid[100][100];
bool visited[100][100];
int max_height = INT_MIN;
int ans = INT_MIN;
int cnt;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y, int danger) {
	return (in_range(x, y) && !visited[x][y] && grid[x][y] > danger);
}

void DFS(int x, int y, int danger) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (can_go(nx, ny, danger)) {
			visited[nx][ny] = true;
			DFS(nx, ny, danger);
		}
	}
}

void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	cnt = 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			max_height = max(max_height, grid[i][j]);
		}
	}

	for (int danger = 0; danger < max_height; danger++) {
		setup();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && grid[i][j] > danger) {
					visited[i][j] = true;
					DFS(i, j, danger);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}
	
	cout << ans;
}