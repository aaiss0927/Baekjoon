#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	while (true) {
		cin >> x >> y;
		if (x == 0 && y == 0) {
			break;
		}
		if (y % x == 0) {
			cout << "factor\n";
		}
		else if (x % y == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
	}
}