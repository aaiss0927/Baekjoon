#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int board[100][100]{ 0 };
	bool visited[100][100]{ false };
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };

	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	queue<vector<int>> q;
	q.push({ 0, 0, 1 });
	visited[0][0] = true;
	while (!q.empty()) {
		vector<int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int x = cur[0] + dx[i];
			int y = cur[1] + dy[i];

			if (board[x][y] == 0) {
				continue;
			}

			if (x < 0 || x >= N || y < 0 || y >= M) {
				continue;
			}

			if (visited[x][y]) {
				continue;
			}

			q.push({ x, y, cur[2] + 1});
			visited[x][y] = true;

			if (x == N - 1 && y == M - 1) {
				cout << cur[2] + 1;
				return 0;
			}
		}
	}
}