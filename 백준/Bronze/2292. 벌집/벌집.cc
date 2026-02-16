#include <iostream>
using namespace std;

int main() {
	int N, rng = 2, i = 1;
	cin >> N;
	if (N == 1) {
		cout << 1;
	}
	else {
		while (N >= rng) {
			rng += 6 * i;
			i++;
		}
		cout << i;
	}

	return 0;
}