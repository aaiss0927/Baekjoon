#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

int w, h;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;
vector<vector<bool>> visited;
vector<vector<int>> dist_from_cur;

bool in_range(int x, int y) {
	if (x == 0) {
		if (y >= 0 && y <= w)
			return true;
		else return false;
	}

	else if (x == h) {
		if (y >= 0 && y <= w)
			return true;
		else return false;
	}

	else if (x > 0 && x < h) {
		if (y == 0 || y == w)
			return true;
		else return false;
	}

	else return false;
}

pair<int, int> encode(int dir, int dist) {
	int x, y;

	if (dir == 1) {
		x = 0; y = dist;
	}
	else if (dir == 2) {
		x = h; y = dist;
	}
	else if (dir == 3) {
		x = dist; y = 0;
	}
	else {
		x = dist; y = w;
	}

	return { x, y };
}

pair<int, int> decode(int x, int y) {
	int dir, dist;

	if (x == 0) {
		dir = 1; dist = y;
	}
	else if (x == h) {
		dir = 2; dist = y;
	}
	else if (y == 0) {
		dir = 3; dist = x;
	}
	else if (y == w) {
		dir = 4; dist = x;
	}

	return { dir, dist };
}

void bfs() {
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		int dir, dist;
		tie(dir, dist) = decode(x, y);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!in_range(nx, ny))
				continue;

			int ndir, ndist;
			tie(ndir, ndist) = decode(nx, ny);

			if (!visited[ndir - 1][ndist]) {
				q.push({ nx, ny });
				visited[ndir - 1][ndist] = true;
				if (dist_from_cur[dir - 1][dist] + 1 < dist_from_cur[ndir - 1][ndist])
					dist_from_cur[ndir - 1][ndist] = dist_from_cur[dir - 1][dist] + 1;
			}
		}
	}
}

int main() {
	cin >> w >> h;
	visited.push_back(vector<bool>(w + 1)); // north
	visited.push_back(vector<bool>(w + 1)); // south
	visited.push_back(vector<bool>(h + 1)); // west
    visited.push_back(vector<bool>(h + 1)); // east
	dist_from_cur.push_back(vector<int>(w + 1, INT_MAX)); // north
	dist_from_cur.push_back(vector<int>(w + 1, INT_MAX)); // south
	dist_from_cur.push_back(vector<int>(h + 1, INT_MAX)); // west
	dist_from_cur.push_back(vector<int>(h + 1, INT_MAX)); // east
	int n; cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int dir, dist; cin >> dir >> dist;
		v.push_back(encode(dir, dist));
	}

	int cur_dir, cur_dist; cin >> cur_dir >> cur_dist;
	int cur_x, cur_y;
	tie(cur_x, cur_y) = encode(cur_dir, cur_dist);

	q.push({ cur_x, cur_y });
	visited[cur_dir - 1][cur_dist] = true;
	dist_from_cur[cur_dir - 1][cur_dist] = 0;
	bfs();

	int sum = 0;

	for (auto v_ : v) {
		int x, y;
		tie(x, y) = v_;
		int dir, dist;
		tie(dir, dist) = decode(x, y);

		sum += dist_from_cur[dir - 1][dist];
	}

	cout << sum;
}