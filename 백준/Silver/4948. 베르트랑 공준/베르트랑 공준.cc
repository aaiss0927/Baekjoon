#include <iostream>
#include <cmath>
using namespace std;

int countP(int n) {
	bool* check = new bool[2 * n + 1] { false };
	check[0] = true;
	check[1] = true;
	int cnt = 0;

	for (int i = 2; i <= sqrt(2 * n); i++) {
		if (check[i]) continue;
		for (int j = 2; i * j <= 2 * n; j++) {
			check[i * j] = true;
		}
	}

	for (int i = n + 1; i <= 2 * n; i++) {
		if (!check[i]) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n;
	do {
		cin >> n;
		if (n == 0) {
			return 0;
		}
		cout << countP(n) << '\n';
	} while (n);
}