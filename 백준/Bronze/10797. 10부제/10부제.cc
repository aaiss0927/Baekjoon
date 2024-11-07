#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		int m; cin >> m;

		if (n == m)
			cnt++;
	}

	cout << cnt;
}