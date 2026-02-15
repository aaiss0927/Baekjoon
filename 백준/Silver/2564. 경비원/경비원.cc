#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int w, h;

int encode(int dir, int dist) {
	if (dir == 1) {
		return dist;
	}
	else if (dir == 4) {
		return w + dist;
	}
	else if (dir == 2) {
		return w + h + (w - dist);
	}
	else {
		return w + h + w + (h - dist);
	}
}

int main() {
	cin >> w >> h;
	int total = 2 * (w + h);
	int n; cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int dir, dist; cin >> dir >> dist;
		v.push_back(encode(dir, dist));
	}

	int cur_dir, cur_dist; cin >> cur_dir >> cur_dist;
	int cur = encode(cur_dir, cur_dist);

	int sum = 0;

	for (auto v_ : v)
		sum += abs(cur - v_) < total - abs(cur - v_) ? abs(cur - v_) : total - abs(cur - v_);

	cout << sum;
}