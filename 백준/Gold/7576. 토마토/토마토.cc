#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;

vector<vector<int>> box;
vector<vector<int>> result;
vector<vector<bool>> visited;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(vector<pair<int, int>> v) {
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		visited[v[i].first][v[i].second] = true;
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int x = cur.first + dx[i];
			int y = cur.second + dy[i];

			if (x < 0 || x >= N || y < 0 || y >= M) {
				continue;
			}

			if (visited[x][y]) {
				continue;
			}

			if (box[x][y] == -1) {
				continue;
			}

			q.push({ x, y });
			visited[x][y] = true;
			result[x][y] = result[cur.first][cur.second] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> start_pnt;

	cin >> M >> N;

	box = vector<vector<int>>(N, vector<int>(M));
	result = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				start_pnt.push_back({ i, j });
			}
			if (box[i][j] == -1) {
				result[i][j] = -1;
			}
		}
	}

	bfs(start_pnt);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] != 1 && result[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (result[i][j] > max) {
				max = result[i][j];
			}
		}
	}
	cout << max;
}