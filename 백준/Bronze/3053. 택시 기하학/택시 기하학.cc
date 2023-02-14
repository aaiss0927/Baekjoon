#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R;
	cin >> R;

	const double PI = 3.14159265358979;
	cout << fixed << setprecision(6) <<
		PI * pow(R, 2) << '\n' << 2 * pow(R, 2);
}