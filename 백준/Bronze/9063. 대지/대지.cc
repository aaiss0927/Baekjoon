#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	int s_x, s_y, e_x, e_y;
	s_x = s_y = 10001;
	e_x = e_y = -10001;

	while (n--) {
		int x, y; cin >> x >> y;

		if (x < s_x) {
			s_x = x;
		}

		if (x > e_x) {
			e_x = x;
		}

		if (y < s_y) {
			s_y = y;
		}

		if (y > e_y) {
			e_y = y;
		}
	}

	cout << (e_x - s_x) * (e_y - s_y);
}