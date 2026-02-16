#include <iostream>
#include <cmath>
using namespace std;

long double n;

int main() {
	cin >> n;

	cout << int(ceil(((3 + sqrt(9 + 12 * (n - 1))) / 6)));
}