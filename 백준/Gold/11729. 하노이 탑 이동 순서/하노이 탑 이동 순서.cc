#include <iostream>
using namespace std;

void althm_hanoi(int n, int a, int b) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	althm_hanoi(n - 1, a, 6 - a - b);
	cout << a << ' ' << b << '\n';
	althm_hanoi(n - 1, 6 - a - b, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	cout << (1 << n) - 1 << '\n';
	althm_hanoi(n, 1, 3);
}