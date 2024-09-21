#include <iostream>
#include <vector>
using namespace std;

int w, h;
int grid[50][50];
bool visited[50][50];

int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int cnt;

bool in_range(int x, int y) {
	return (x >= 0 && x < h) && (y >= 0 && y < w);
}

bool can_go(int x, int y) {
	return in_range(x, y) && grid[x][y] && !visited[x][y];
}

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (can_go(nx, ny)) {
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> grid[i][j];
				visited[i][j] = false;
			}
		}

		cnt = 0;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (can_go(i, j)) {
					visited[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}