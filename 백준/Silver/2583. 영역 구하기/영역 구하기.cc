#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt;


void dfs(pair<int ,int> p) {
	visited[p.first][p.second] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int x = p.second + dx[i];
		int y = p.first + dy[i];

		if (x < 0 || x >= N || y < 0 || y >= M) {
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

	cin >> M >> N >> K;
	
	board = vector<vector<int>>(M, vector<int>(N, 1));
	visited = vector<vector<bool>>(M, vector<bool>(N, false));

	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = M - y2; j <= M - y1 - 1; j++) {
			for (int k = x1; k <= x2 - 1; k++) {
				board[j][k] = 0;
			}
		}
	}

	vector<int> result;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				dfs({ i, j });
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}