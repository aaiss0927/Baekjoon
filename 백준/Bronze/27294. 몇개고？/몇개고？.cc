#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, s; cin >> t >> s;

	if (s || !(t >= 12 && t <= 16))
		cout << 280;
	else
		cout << 320;
}