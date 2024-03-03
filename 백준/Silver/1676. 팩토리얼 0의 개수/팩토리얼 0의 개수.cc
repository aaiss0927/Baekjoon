#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;

	int exp = 1;
	int cnt = 0;

	while (true) {
		if (n / (int)pow(5, exp) == 0) {
			break;
		}

        cnt += n / (int)pow(5, exp++);
	}

	cout << cnt;
}