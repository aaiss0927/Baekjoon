#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

int n;
int s_size;
int gaze;
int grid[21][21];
bool is_visit[21][21];
int dist[21][21];
vector<pair<int, pair<int, int>>> fishes;
// (크기, (x, y))
int cur_x, cur_y;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool is_range(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

bool can_go(int x, int y) {
	return (is_range(x, y) && !is_visit[x][y] && s_size >= grid[x][y]);
}

void set_up() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			is_visit[i][j] = false;
			dist[i][j] = 0;
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
				is_visit[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int get_dist(int cur_x, int cur_y, int tar_x, int tar_y) {
	set_up();
	is_visit[cur_x][cur_y] = true;
	q.push({ cur_x, cur_y });
	bfs();

	return dist[tar_x][tar_y];
}

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first > b.first)
		return false;

	else if (a.first == b.first) {
		if (a.second.first > b.second.first)
			return false;

		else if (a.second.first == b.second.first)
			if (a.second.second > b.second.second)
				return false;
	}

	return true;
}

pair<int, pair<int, int>> get_target_fish() {
	vector<pair<int, pair<int, int>>> target_fishes;
	// (거리, (x, y))

	for (int i = 0; i < fishes.size(); i++) {
		if (fishes[i].first < s_size) {
			int tar_x = fishes[i].second.first;
			int tar_y = fishes[i].second.second;
			int dst = get_dist(cur_x, cur_y, tar_x, tar_y);

			if (dst > 0)
				target_fishes.push_back({ dst, {tar_x, tar_y} });
		}
	}

	if (target_fishes.empty())
		return { 0, { -1, -1} };

	if (target_fishes.size() == 1)
		return target_fishes.front();

	sort(target_fishes.begin(), target_fishes.end(), cmp);
	return target_fishes.front();
}

void remove_target_fish(int x, int y) {
	for (auto i = fishes.begin(); i != fishes.end(); i++) {
		int f_x = (*i).second.first;
		int f_y = (*i).second.second;

		if (x == f_x && y == f_y) {
			fishes.erase(i);
			grid[x][y] = 0;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];

			if (grid[i][j] == 9) {
				cur_x = i; cur_y = j;
			}

			else if (grid[i][j] != 0)
				fishes.push_back({ grid[i][j], {i, j} });
		}
	}

	int t = 0;
	s_size = 2;
	gaze = 0;

	while (true) {
		pair<int, pair<int, int >> target = get_target_fish();
		int dst, tar_x, tar_y;
		dst = target.first;
		tar_x = target.second.first; tar_y = target.second.second;

		if (dst == 0)
			break;
		
		grid[cur_x][cur_y] = 0;
		grid[tar_x][tar_y] = 0;
		cur_x = tar_x; cur_y = tar_y;
		t += dst; gaze++;

		if (gaze == s_size) {
			s_size++; gaze = 0;
		}

		remove_target_fish(tar_x, tar_y);
	}

	cout << t;
}