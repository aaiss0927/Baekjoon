#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
pair<int, int> o;
vector<int> ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool is_red_first(pair<int, int> r, pair<int, int> b, int dir) {
	if (dir == 0) {
		return (r.first < b.first);
	}

	else if (dir == 1) {
		return (r.second < b.second);
	}

	else if (dir == 2) {
		return (r.first > b.first);
	}

	else if (dir == 3) {
		return (r.second > b.second);
	}
}

bool is_finished(pair<int, int> r, pair<int, int> b, int cnt) {
	return (cnt <= 10 && r == o && b != o);
}

void solve(vector<vector<char>> grid, pair<int, int> r, pair<int, int> b, int cnt, int dir) {
	if (cnt > 10) {
		return;
	}

	int rx, ry, bx, by;
	rx = r.first; ry = r.second; bx = b.first; by = b.second;
	int nx_r, ny_r, nx_b, ny_b;
	vector<vector<char>> n_grid(grid);

	if (is_red_first(r, b, dir)) {
		nx_r = rx + dx[dir];
		ny_r = ry + dy[dir];

		while (n_grid[nx_r][ny_r] != '#' && n_grid[nx_r][ny_r] != 'B') {
			n_grid[rx][ry] = '.';
			rx = nx_r; ry = ny_r;

			if (rx == o.first && ry == o.second) {
				break;
			}

			n_grid[rx][ry] = 'R';

			nx_r = rx + dx[dir];
			ny_r = ry + dy[dir];
		}

		nx_b = bx + dx[dir];
		ny_b = by + dy[dir];

		while (n_grid[nx_b][ny_b] != '#' && n_grid[nx_b][ny_b] != 'R') {
			n_grid[bx][by] = '.';
			bx = nx_b; by = ny_b;

			if (bx == o.first && by == o.second) {
				return;;
			}

			n_grid[bx][by] = 'B';

			nx_b = bx + dx[dir];
			ny_b = by + dy[dir];
		}
	}

	else {
		nx_b = bx + dx[dir];
		ny_b = by + dy[dir];

		while (n_grid[nx_b][ny_b] != '#' && n_grid[nx_b][ny_b] != 'R') {
			n_grid[bx][by] = '.';
			bx = nx_b; by = ny_b;

			if (bx == o.first && by == o.second) {
				return;;
			}

			n_grid[bx][by] = 'B';

			nx_b = bx + dx[dir];
			ny_b = by + dy[dir];
		}

		nx_r = rx + dx[dir];
		ny_r = ry + dy[dir];

		while (n_grid[nx_r][ny_r] != '#' && n_grid[nx_r][ny_r] != 'B') {
			n_grid[rx][ry] = '.';
			rx = nx_r; ry = ny_r;

			if (rx == o.first && ry == o.second) {
				break;
			}

			n_grid[rx][ry] = 'R';

			nx_r = rx + dx[dir];
			ny_r = ry + dy[dir];
		}
	}

	if (is_finished({rx, ry}, {bx, by}, cnt)) {
		ans.push_back(cnt);
		return;
	}

	solve(n_grid, { rx, ry }, { bx, by }, cnt + 1, (dir + 1) % 4);
	solve(n_grid, { rx, ry }, { bx, by }, cnt + 1, (dir + 3) % 4);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v(11);
	vector<vector<char>> grid(11, vector<char>(11));
	cin >> n >> m;
	pair<int, int> r, b;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int j = 0; j < m; j++) {
			grid[i][j] = str[j];

			if (grid[i][j] == 'O') {
				o = { i, j };
			}

			else if (grid[i][j] == 'R') {
				r = { i, j };
			}

			else if (grid[i][j] == 'B') {
				b = { i, j };
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		solve(grid, r, b, 1, i);
	}

	if (ans.empty())
		cout << -1;

	else {
		sort(ans.begin(), ans.end());
		cout << ans.front();
	}
}