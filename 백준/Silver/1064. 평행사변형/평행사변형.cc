#include <bits/stdc++.h>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point()
		: x(0), y(0) {}
	Point(int x_, int y_)
		: x(x_), y(y_) {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
};

bool line(Point f, Point s, Point t) {
	bool condition;
	if ((((s.getX() - f.getX()) != 0) && (((t.getX() - s.getX())) != 0))) {
		condition = (double((s.getY() - f.getY())) / (s.getX() - f.getX()) ==
			double((t.getY() - s.getY())) / (t.getX() - s.getX()));
	}
	else if ((((s.getX() - f.getX()) == 0) && (((t.getX() - s.getX())) == 0))) {
		return true;
	}
	else {
		condition = false;
	}

	if (condition) {
		return true;
	}
	return false;
}

double get_length(Point f, Point s) {
	return sqrt(pow((f.getX() - s.getX()), 2) + pow((f.getY() - s.getY()), 2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x_A, y_A, x_B, y_B, x_C, y_C;
	cin >> x_A >> y_A >> x_B >> y_B >> x_C >> y_C;
	Point A(x_A, y_A), B(x_B, y_B), C(x_C, y_C);
	
	double a, b, c;
	a = get_length(B, C);
	b = get_length(C, A);
	c = get_length(A, B);
	
	double maximum = max(max(a, b), c);
	double minimum = min(min(a, b), c);
	double result;
	if (line(A, B, C)) {
		result = -1.0;
	}
	else {
		result = 2 * (maximum - minimum);
	}
	cout << fixed << setprecision(12) << result;
}