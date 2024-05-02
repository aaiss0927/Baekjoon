#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

void move(vector<vector<bool>>& cannot, vector<vector<int>>& n_grid, int& x, int& y, int& nx, int& ny, int k) {
	n_grid[nx][ny] = n_grid[x][y];
	cannot[nx][ny] = cannot[x][y];
	n_grid[x][y] = 0;
	cannot[nx][ny] = false;
	x = nx; y = ny;
	nx = x + dx[k];
	ny = y + dy[k];
}

void add(vector<vector<bool>>& cannot, vector<vector<int>>& n_grid, int& x, int& y, int& nx, int& ny, int k) {
	n_grid[nx][ny] *= 2;
	cannot[nx][ny] = true;
	n_grid[x][y] = 0;
	x = nx; y = ny;
	nx = x + dx[k];
	ny = y + dy[k];
}

void solve(vector<vector<int>> grid, int cnt) {
	if (cnt > 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] > ans) {
					ans = grid[i][j];
				}
			}
		}

		return;
	}

	for (int k = 0; k < 4; k++) {
		vector<vector<int>> n_grid(grid);
		vector<vector<bool>> cannot(21, vector<bool>(21));

		if (k < 2) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (n_grid[i][j] == 0)
						continue;

					int x = i; int y = j;
					int nx = x + dx[k]; int ny = y + dy[k];

					while (in_range(nx, ny)) {
						if (n_grid[nx][ny] == 0) {
							move(cannot, n_grid, x, y, nx, ny, k);
						}

						else if (!cannot[x][y] && !cannot[nx][ny] && (n_grid[nx][ny] == n_grid[x][y])) {
							add(cannot, n_grid, x, y, nx, ny, k);
						}

						else {
							break;
						}
					}
				}
			}

			solve(n_grid, cnt + 1);
		}

		else {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					if (n_grid[i][j] == 0)
						continue;

					int x = i; int y = j;
					int nx = x + dx[k]; int ny = y + dy[k];

					while (in_range(nx, ny)) {
						if (n_grid[nx][ny] == 0) {
							move(cannot, n_grid, x, y, nx, ny, k);
						}

						else if (!cannot[x][y] && !cannot[nx][ny] && (n_grid[nx][ny] == n_grid[x][y])) {
							add(cannot, n_grid, x, y, nx, ny, k);
						}

						else {
							break;
						}
					}
				}
			}

			solve(n_grid, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<vector<int>> grid(21, vector<int>(21));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	solve(grid, 1);
	cout << ans;
}