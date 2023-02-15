#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if ((a == 60) && (b == 60) && (c == 60)) {
		cout << "Equilateral";
	}
	else if ((a + b + c == 180) && ((a == b) || (b == c) || (c == a))) {
		cout << "Isosceles";
	}
	else if ((a + b + c == 180) && ((a != b) && (b != c) && (c != a))) {
		cout << "Scalene";
	}
	else if (a + b + c != 180) {
		cout << "Error";
	}
}