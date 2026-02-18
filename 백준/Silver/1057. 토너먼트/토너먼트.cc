#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k, l; cin >> n >> k >> l;
	int cnt = 0;

	while (k != l) {
		k = (k + 1) / 2;
		l = (l + 1) / 2;
		cnt++;
	}

	cout << cnt;
}