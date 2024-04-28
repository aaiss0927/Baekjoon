#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int sing = 1;
	int cnt = 0;

	while (n != 0) {
		if (n < sing) {
			sing = 1;
		}

		n -= sing;
		sing++;
		cnt++;
	}

	cout << cnt;
}