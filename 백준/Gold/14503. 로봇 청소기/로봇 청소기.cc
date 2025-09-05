#include <iostream>
using namespace std;

int n, m;
int grid[50][50];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m);
}

bool is_clear(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!is_range(nx, ny))
			continue;

		if (grid[nx][ny] == 0)
			return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	int r, c, d; cin >> r >> c >> d;
	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	while (true) {
		if (grid[r][c] == 0) {
			grid[r][c] = 2;
			cnt++;
		}

		if (is_clear(r, c)) {
			if (is_range(r - dx[d], c - dy[d]) && grid[r - dx[d]][c - dy[d]] != 1) {
				r -= dx[d]; c -= dy[d];
			}
			else
				break;
		}
		else {
			do {
				d = (d + 3) % 4;
			} while (grid[r + dx[d]][c + dy[d]] != 0);
				
			r += dx[d]; c += dy[d];
		}
	}

	cout << cnt;
}