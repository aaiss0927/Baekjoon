#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	list<char> editor;
	for (auto c : s) {
		editor.push_back(c);
	}
	auto t = editor.end();

	int M;
	cin >> M;

	while (M--) {
		char sel;
		cin >> sel;
		if (sel == 'L') {
			if (t != editor.begin()) {
				t--;
			}
		}
		if (sel == 'D') {
			if (t != editor.end()) {
				t++;
			}
		}
		if (sel == 'B') {
			if (t != editor.begin()) {
				t--;
				t = editor.erase(t);
			}
		}
		if (sel == 'P') {
			char add;
			cin >> add;
			editor.insert(t, add);
		}
	}
	for (auto i : editor) {
		cout << i;
	}
}