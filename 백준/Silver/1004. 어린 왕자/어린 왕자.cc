#include <iostream>
#include <cmath>
using namespace std;

bool is_in(int x, int y, int cx, int cy, int r) {
	int clen_square = pow((x - cx), 2) + pow((y - cy), 2);
	int r_square = pow(r, 2);

	if (clen_square < r_square) return true;
	
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int T; cin >> T;

	while (T--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int n; cin >> n;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int cx, cy, r; cin >> cx >> cy >> r;

			if (is_in(x1, y1, cx, cy, r) ^ is_in(x2, y2, cx, cy, r))
				cnt++;
		}

		cout << cnt << '\n';
	}
}