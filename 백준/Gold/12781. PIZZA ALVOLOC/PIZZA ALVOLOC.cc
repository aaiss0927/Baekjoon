#include <iostream>
using namespace std;

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

	if (abc * abd < 0 && cda * cdb < 0)
		return true;

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	cout << is_cross(x1, y1, x2, y2, x3, y3, x4, y4);
}