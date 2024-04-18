#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c; cin >> a >> b >> c;

	while (!(a == 0 && b == 0 && c == 0)) {
		if (a + b <= c || b + c <= a || c + a <= b) {
			cout << "Invalid\n";
		}

		else if (a == b && b == c) {
			cout << "Equilateral\n";
		}

		else if (a == b || b == c || c == a) {
			cout << "Isosceles\n";
		}

		else {
			cout << "Scalene\n";
		}

		cin >> a >> b >> c;
	}

	
}