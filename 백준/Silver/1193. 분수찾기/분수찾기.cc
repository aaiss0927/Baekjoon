#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int x = 1, y = 1;
	int count = 1;
	while (count < n) {
		while (!((x + y) % 2)) {
			if (x == 1) {
				y++;
				count++;
				break;
			}
			x--;
			y++;
			count++;
			if (!(count < n)) {
				break;
			}
		}
		if (!(count < n)) {
			break;
		}
		while (((x + y) % 2)) {
			if (y == 1) {
				x++;
				count++;
				break;
			}
			x++;
			y--;
			count++;
			if (!(count < n)) {
				break;
			}
		}
		if (!(count < n)) {
			break;
		}
	}
	cout << x << '/' << y;
}