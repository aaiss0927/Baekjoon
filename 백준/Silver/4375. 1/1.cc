#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;

	while (cin >> n) {
		int ones = 1;
		int cnt = 1;

		while (ones % n != 0) {
			ones = (ones * 10 + 1) % n;
			cnt++;
		}

		cout << cnt << '\n';
	}
}