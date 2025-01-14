#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m; cin >> m;
	int ans = 1;

	while (m--) {
		int x, y; cin >> x >> y;

		if (ans == x)
			ans = y;
		else if (ans == y)
			ans = x;
	}

	cout << ans;
}