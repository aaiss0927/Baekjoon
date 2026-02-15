#include <iostream>
#include <cmath>
using namespace std;

int w, h, x, y, p, r;
int cnt = 0;

int l2_norm_square(int x1, int y1, int x2, int y2) {
	return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

bool in_sector1(int px, int py) {
	if (l2_norm_square(x, y + r, px, py) <= pow(r, 2))
		return true;
	else return false;
}

bool in_sector2(int px, int py) {
	if (px >= x && px <= x + w && py >= y && py <= y + h)
		return true;
	else return false;
}

bool in_sector3(int px, int py) {
	if (l2_norm_square(x + w, y + r, px, py) <= pow(r, 2))
		return true;
	else return false;
}

bool in_range(int px, int py) {
	if (in_sector1(px, py) || in_sector2(px, py) || in_sector3(px, py))
		return true;
	else return false;
}

int main() {
	cin >> w >> h >> x >> y >> p;
	r = h / 2;

	for (int i = 0; i < p; i++) {
		int px, py; cin >> px >> py;
		
		if (in_range(px, py)) cnt++;
	}

	cout << cnt;
}