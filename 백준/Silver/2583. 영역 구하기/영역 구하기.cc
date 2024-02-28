#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, k;
int grid[100][100];
bool visited[100][100];
int cnt_domain;
vector<int> areas;
int area;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < m && y >= 0 && y < n);
}

bool can_go(int x, int y) {
	return (in_range(x, y) && !visited[x][y] && grid[x][y] == 0);
}

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (can_go(nx, ny)) {
			visited[nx][ny] = true;
			area++;
			DFS(nx, ny);
		}
	}
}

void setup() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	cnt_domain = 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = 0;
		}
	}

	while (k--) {
		int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2;

		for (int i = r1; i < r2; i++) {
			for (int j = c1; j < c2; j++) {
				grid[i][j] = 1;
			}
		}
	}

	setup();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (can_go(i, j)) {
				visited[i][j] = true;
				area = 1;
				DFS(i, j);
				cnt_domain++;
				areas.push_back(area);
			}
		}
	}

	sort(areas.begin(), areas.end());
	
	cout << cnt_domain << '\n';
	for (auto v : areas) {
		cout << v << ' ';
	}
}