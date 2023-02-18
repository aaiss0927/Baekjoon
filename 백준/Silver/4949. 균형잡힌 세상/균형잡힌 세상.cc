#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	while (true) {
		getline(cin, s);
		if (s.size() == 1) {
			return 0;
		}
		stack<char> strg;
		bool state = true;
		for (auto i : s) {
			if ((i == '(') || (i == '[')) {
				strg.push(i);
			}

			else if (i == ')') {
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

			else if (i == ']') {
				if (!strg.empty()) {
					if (strg.top() == '[') {
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
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}
}