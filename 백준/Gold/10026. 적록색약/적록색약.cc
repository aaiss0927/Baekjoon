#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n;
int cnt[2];
vector<vector<char>> board;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

bool can_go(int x, int y) {
	return in_range(x, y) && !visited[x][y];
}

void init_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int opt) {
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];

			if (!opt && can_go(nx, ny) && board[nx][ny] == board[x][y]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}

			else if (opt && can_go(nx, ny)) {
				if (board[x][y] == 'R' && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}

				else if (board[x][y] == 'G' && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}

				else if (board[x][y] == 'B' && board[nx][ny] == board[x][y]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}

void init() {
	cin >> n;
	board = vector<vector<char>>(n, vector<char>(n));
	visited = vector<vector<bool>>(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void solve(int opt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j])
				continue;

			visited[i][j] = true;
			q.push({ i, j });
			bfs(opt);
			cnt[opt]++;
		}
	}
}

void print() {
	cout << cnt[0] << ' ' << cnt[1];
}


int main() {
	init();
	solve(0);
	init_visited();
	solve(1);
	print();
}