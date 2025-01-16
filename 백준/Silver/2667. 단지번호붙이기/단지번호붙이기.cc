#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int grp_idx = 1;
int cnt;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<int> grp_size = {0};
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool in_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool can_go(int x, int y) {
	return (in_range(x, y) && !visited[x][y] && grid[x][y]);
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (visited[cx][cy])
			continue;

		grid[cx][cy] = grp_idx;
		visited[cx][cy] = true;
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (can_go(nx, ny))
				q.push({nx, ny});
		}
	}

	grp_idx++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	grid = vector<vector<int>>(n, vector<int>(n));
	visited = vector<vector<int>>(n, vector<int>(n, false));

	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int j = 0; j < n; j++)
			grid[i][j] = str[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (can_go(i, j)) {
				cnt = 0;
				bfs(i, j);
				grp_size.push_back(cnt);
			}
		}
	}

	sort(grp_size.begin(), grp_size.end());

	cout << grp_size.size() - 1 << '\n';

	for (int i = 1; i < grp_size.size(); i++)
		cout << grp_size[i] << '\n';
}