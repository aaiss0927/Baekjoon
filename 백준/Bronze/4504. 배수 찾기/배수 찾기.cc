#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int num = -1;
	while (1) {
		cin >> num;
		if (!num) {
			break;
		}
		if (num % n == 0) {
			cout << num << " is a multiple of " << n << ".\n";
		}
		else {
			cout << num << " is NOT a multiple of " << n << ".\n";
		}
	}
}