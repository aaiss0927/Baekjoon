#include <iostream>
#include <cmath>
using namespace std;

long long power_and_modular(long long a, long long b, long long c) {	
	if (b == 0) {
		return 1;
	}

	if (b == 1) {
		return a;
	}

	if (b % 2 == 0) {
		return ((power_and_modular(a, b / 2, c) * power_and_modular(a, b / 2, c)) % c);
	}

	else {
		return ((power_and_modular(a, b / 2, c) * power_and_modular(a, (b / 2) + 1, c)) % c);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	long long A, B, C; cin >> A >> B >> C;

	cout << power_and_modular(A % C, B, C);
}