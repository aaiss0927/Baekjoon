#include <bits/stdc++.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x_, int y_)
		:x(x_), y(y_) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	bool operator<(Point right) {
		if (this->y < right.y) {
			return true;
		}
		else if (this->y == right.y) {
			if (this->x < right.x) {
				return true;
			}
			return false;
		}
		else {
			return false;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<Point> point;
	int x, y;
	while (N--) {
		cin >> x >> y;
		point.push_back(Point(x, y));
	}
	sort(point.begin(), point.end());
	for (int i = 0; i < point.size(); i++) {
		cout << point[i].getX() << ' ' << point[i].getY() << '\n';
	}
}