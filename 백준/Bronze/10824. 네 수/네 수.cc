#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int B_ = B, D_ = D;
	int digit_B = 0, digit_D = 0;
	while (B_) {
		B_ /= 10;
		digit_B++;
	}
	while (D_) {
		D_ /= 10;
		digit_D++;
	}

	long long f, s;
	f = A * pow(10, digit_B) + B;
	s = C * pow(10, digit_D) + D;
	cout << f + s;
}