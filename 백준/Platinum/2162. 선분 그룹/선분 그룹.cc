#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> p;

int find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = find(p[x]);
}

bool uni(int v, int u) {
	u = find(u);
	v = find(v);

	if (u == v)
		return false;

	if (p[v] < p[u])
		swap(u, v);

	if (p[v] == p[u])
		p[u]--;

	p[v] = u;

	return true;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = (x2 * y3 + x3 * y1 + x1 * y2) - (x3 * y2 + x1 * y3 + x2 * y1);

	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

bool is_cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}

		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}

		if (x1 <= x4 && x3 <= x2) {
			if (min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
				return true;

			else
				return false;
		}

		else
			return false;
	}

	else if (abc * abd <= 0 && cda * cdb <= 0)
		return true;

	else
		return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	p = vector<int>(n, -1);
	vector<vector<int>> line(n, vector<int>(4));
	vector<int> grp_size(n, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> line[i][j];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (is_cross(line[i][0], line[i][1], line[i][2], line[i][3],
				line[j][0], line[j][1], line[j][2], line[j][3]))
				uni(i, j);
		}
	}

	for (int i = 0; i < n; i++)
			grp_size[find(i)]++;

	int cnt = 0;
	int max_size = 1;

	for (int i = 0; i < n; i++)
		if (grp_size[i] > 0) {
			cnt++;
			max_size = max(max_size, grp_size[i]);
		}
	
	cout << cnt << '\n' << max_size;
}