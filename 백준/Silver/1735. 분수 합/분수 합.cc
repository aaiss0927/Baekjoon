#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}

	while (b) {
		int first, second;

		if (b > a - b) {
			first = b; second = a - b;
		}
		
		else {
			first = a - b; second = b;
		}

		a = first; b = second;
	}

	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int numer1, denom1, numer2, denom2;
	cin >> numer1 >> denom1 >> numer2 >> denom2;
	
	int mul1 = lcm(denom1, denom2) / denom1;
	int mul2 = lcm(denom1, denom2) / denom2;

	int numer = numer1 * mul1 + numer2 * mul2;
	int denom = lcm(denom1, denom2);

	int div = gcd(numer, denom);
	numer /= div; denom /= div;

	cout << numer << ' ' << denom;
}