#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	int A = 300, B = 60, C = 10;
	int count_A = 0, count_B = 0, count_C = 0;

	count_A = T / A;
	count_B = (T - A * count_A) / B;
	count_C = (T - A * count_A - B * count_B) / C;

	if (A * count_A + B * count_B + C * count_C == T) {
		cout << count_A << ' ' << count_B << ' ' << count_C;
	}
	else {
		cout << -1;
	}
}