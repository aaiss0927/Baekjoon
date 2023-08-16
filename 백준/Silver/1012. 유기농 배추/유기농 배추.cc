#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, K;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt;

void dfs(pair<int, int> p) {
	visited[p.first][p.second] = true;

	for (int i = 0; i < 4; i++) {
		int x = p.second + dx[i];
		int y = p.first + dy[i];

		if (x < 0 || x >= M || y < 0 || y >= N) {
			continue;
		}

		if (visited[y][x]) {
			continue;
		}

		if (board[y][x] == 0) {
			continue;
		}

		dfs({ y, x });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		cnt = 0;
		cin >> M >> N >> K;

		board = vector<vector<int>>(N, vector<int>(M, 0));
		visited = vector<vector<bool>>(N, vector<bool>(M, false));

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1 && !visited[i][j]) {
					dfs({ i, j });
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}