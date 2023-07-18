#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		int a, b;
		a = b = 0;

		if (M == 1 && N == 1) {
			cout << "1\n";
			continue;
		}

		bool flag = false;

		while (M * a + x <= LCM(M, N)) {
			if (M * a + x > N * b + y) {
				b++;
			}
			else if (M * a + x < N * b + y) {
				a++;
			}
			else {
				cout << M * a + x << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "-1\n";
		}
	}
}