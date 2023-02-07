#include <bits/stdc++.h>
using namespace std;

class Circle {
private:
	int cx, cy, r;
public:
	Circle()
		: cx(0), cy(0), r(0) {}
	Circle(int cx_, int cy_, int r_)
		: cx(cx_), cy(cy_), r(r_) {}
	int get_cx() {
		return cx;
	}
	int get_cy() {
		return cy;
	}
	int get_r() {
		return r;
	}
	void set_cx(int cx_) {
		cx = cx_;
	}
	void set_cy(int cy_) {
		cy = cy_;
	}
	void set_r(int r_) {
		r = r_;
	}
};

bool judge_in(int x, int y, Circle circle) {
	bool condition;
	condition = ((pow((x - circle.get_cx()), 2) + pow((y - circle.get_cy()), 2))
		< pow(circle.get_r(), 2));
	if (condition) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		Circle* circle = new Circle[n];
		int cx, cy, r;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> r;
			circle[i].set_cx(cx);
			circle[i].set_cy(cy);
			circle[i].set_r(r);
		}
		
		bool* point_begin_in = new bool[n];
		for (int i = 0; i < n; i++) {
			if (judge_in(x1, y1, circle[i])) {
				point_begin_in[i] = true;
			}
			else {
				point_begin_in[i] = false;
			}
		}

		bool* point_end_in = new bool[n];
		for (int i = 0; i < n; i++) {
			if (judge_in(x2, y2, circle[i])) {
				point_end_in[i] = true;
			}
			else {
				point_end_in[i] = false;
			}
		}

		int uni = 0, inter = 0;
		for (int i = 0; i < n; i++) {
			if (point_begin_in[i] || point_end_in[i]) {
				uni++;
			}
			if (point_begin_in[i] && point_end_in[i]) {
				inter++;
			}
		}
		cout << uni - inter << '\n';
	}
}