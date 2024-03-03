#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

// 0 - 빈칸, 1 - 벽, 2 - 바이러스

int n, m;
int grid[8][8];
int temp_grid[8][8];
bool visited[8][8];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;
vector<pair<int, int>> candidates;
int ans = 0;

bool in_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool can_go(int x, int y) {
	return (in_range(x, y) && !visited[x][y] && temp_grid[x][y] == 0);
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
				temp_grid[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
}

vector<int> v;

void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp_grid[i][j] = grid[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		temp_grid[candidates[v[i]].first][candidates[v[i]].second] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_grid[i][j] == 2) {
				visited[i][j] = true;
				q.push({ i, j });
			}
		}
	}
}

int get_cnt() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp_grid[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void choose(int next) {
	if (v.size() == 3) {
		setup();
		BFS();

		int cnt = get_cnt();
		ans = max(ans, cnt);

		return;
	}

	for (int i = next; i < candidates.size(); i++) {
		v.push_back(i);
		choose(i + 1);
		v.pop_back();
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 0) {
				candidates.push_back({ i, j });
			}
		}
	}

	choose(0);

	cout << ans;
}