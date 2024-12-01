#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x, y; cin >> x >> y;
	int n; cin >> n;
	int cls_x, cls_y;
	int cls_dist = INT_MAX;

	while (n--) {
		int x_, y_; cin >> x_ >> y_;

		if (abs(x - x_) + abs(y - y_) < cls_dist) {
			cls_x = x_; cls_y = y_;
			cls_dist = abs(x - x_) + abs(y - y_);
		}
	}

	cout << cls_x << ' ' << cls_y;
}