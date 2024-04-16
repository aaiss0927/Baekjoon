#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	int b;
	cin >> n >> b;

	int mult = 1;
	int ans = 0;

	for (int i = n.length() - 1; i >= 0; i--) {
		if (isalpha(n[i])) {
			ans += ((n[i] - '0') - 7) * mult;
			mult *= b;
		}

		else {
			ans += (n[i] - '0') * mult;
			mult *= b;
		}
	}

	cout << ans;
}