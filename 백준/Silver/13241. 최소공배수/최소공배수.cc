#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
	if (a < b) {
		swap(a, b);
	}
	
	while (b) {
		int first = b;
		int second = a - b;

		if (first > second) {
			a = first;
			b = second;
		}

		else {
			a = second;
			b = first;
		}
	}

	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long a, b; cin >> a >> b;
	cout << (a * b) / gcd(a, b);
}