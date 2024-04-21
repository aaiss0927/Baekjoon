#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	int x, y;

	x = ((c * e) - (b * f)) / ((a * e) - (b * d));
	y = ((c * d) - (a * f)) / ((b * d) - (e * a));

	cout << x << ' ' << y;
}