#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int n, L, R;
int A[50][50];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool visited[50][50];
int A_area[50][50];
int cnt;
queue<pair<int, int>> q;

bool is_range(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

bool can_go(int x, int y) {
	return (is_range(x, y) && !visited[x][y]);
}

void set_up() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			A_area[i][j] = 0;
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (can_go(nx, ny)) {
				if ((abs(A[x][y] - A[nx][ny]) >= L) && (abs(A[x][y] - A[nx][ny]) <= R)) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
					A_area[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> L >> R;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	int t = 0;

	while (true) {
		set_up();
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;

				q.push({ i, j });
				visited[i][j] = true;
				A_area[i][j] = cnt;
				bfs();
				cnt++;
			}
		}

		if (cnt == n * n) break;

		vector<vector<pair<int, int>>> v(cnt);
		vector<int> s(cnt, 0);

		// v[0] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
		// s[0] = 140

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				s[A_area[i][j]] += A[i][j];
				v[A_area[i][j]].push_back({ i, j });
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int num = v[i].size();

			for (int j = 0; j < v[i].size(); j++) {
				int x = v[i][j].first;
				int y = v[i][j].second;

				A[x][y] = s[i] / num;
			}
		}

		t++;
	}

	cout << t;
}