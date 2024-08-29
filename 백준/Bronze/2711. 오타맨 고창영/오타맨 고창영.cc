#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;

	while (T--) {
		int n; cin >> n;
		string str; cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (i == n - 1)
				continue;

			cout << str[i];
		}
		cout << '\n';
	}
}