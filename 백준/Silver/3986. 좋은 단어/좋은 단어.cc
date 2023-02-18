#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	string s;
	int count = 0;
	while (N--) {
		cin >> s;
		stack<char> strg;
		for (auto c : s) {
			if ((strg.empty()) || (c != strg.top())) {
				strg.push(c);
			}
			else {
				strg.pop();
			}
		}
		if (strg.empty()) {
			count++;
		}
	}
	cout << count;
}