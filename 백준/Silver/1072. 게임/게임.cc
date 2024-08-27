#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long x, y;
	int z;
	cin >> x >> y;
	z = int((double(y) * 100 / x));

	if (z >= 99) {
		cout << -1;
		return 0;
	}

	int temp = z;
	int cnt = 0;

	while (temp == z) {
		x++; y++;
		temp = int((double(y) * 100 / x));
		cnt++;
	}

	cout << cnt;
}