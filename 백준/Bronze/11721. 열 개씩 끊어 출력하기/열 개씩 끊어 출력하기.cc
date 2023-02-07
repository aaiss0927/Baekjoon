#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int length = s.length();
	for (int i = 0; i < length; i++) {
		cout << s[i];
		if (!((i + 1) % 10)) {
			cout << '\n';
		}
	}
}