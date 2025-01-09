#include <iostream>
#include <vector>
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

	if (abc * abc == 0 && cda * cdb == 0) {
		if (x1 > x2)
			swap(x1, x2), swap(y1, y2);

		if (x3 > x4)
			swap(x3, x4), swap(y3, y4);

		return x1 <= x4 && x3 <= x2 &&
			   min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2);
	}

	return abc * abd <= 0 && cda * cdb <= 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int x_left, y_top, x_right, y_bot;
		cin >> x_left >> y_top >> x_right >> y_bot;

		int xmin = min(x_left, x_right);
		int xmax = max(x_left, x_right);
		int ymin = min(y_top, y_bot);
		int ymax = max(y_top, y_bot);

		vector<vector<int>> line(4, vector<int>(4));
		line[0] = { xmin, ymin, xmax, ymin };
		line[1] = { xmax, ymin, xmax, ymax };
		line[2] = { xmax, ymax, xmin, ymax };
		line[3] = { xmin, ymax, xmin, ymin };

		bool flag = false;

		for (int i = 0; i < 4; i++) {
			if (is_cross(x1, y1, x2, y2, line[i][0], line[i][1], line[i][2], line[i][3])) {
				flag = true;
				break;
			}
		}

		if (xmin < min(x1, x2) && xmax > max(x1, x2) &&
			ymin < min(y1, y2) && ymax > max(y1, y2))
			flag = true;

		if (flag)
			cout << "T\n";
		else
			cout << "F\n";
	}
}