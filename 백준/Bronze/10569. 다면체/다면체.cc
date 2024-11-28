#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int v, e; cin >> v >> e;

		cout << e - v + 2 << '\n';
	}
}