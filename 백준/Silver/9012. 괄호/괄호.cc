#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		stack<char> strg;
		bool state = true;
		for (auto c : s) {
			if (c == '(') {
				strg.push(c);
			}
			else {
				if (!strg.empty()) {
					if (strg.top() == '(') {
						strg.pop();
					}
					else {
						state = false;
					}
				}
				else {
					state = false;
				}
			}
		}
		if (!strg.empty() || !state) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}